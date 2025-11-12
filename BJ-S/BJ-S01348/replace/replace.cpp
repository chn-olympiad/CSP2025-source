#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
const int M=5e6+5;

int n,q;
string s[N][2],t[N][2];
bool check(string s) {
    int cnt=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='b')cnt++;
        else if(s[i]!='a'&&s[i]!='b')return 0;
    return cnt==1;
}

struct Node {
    int p,pre,suf,len,id;
    bool operator < (const Node &rhs) const {
        if(pre==rhs.pre)return suf<rhs.suf;
        return pre<rhs.pre;
    }
}a[N],b[N];

map<int,vector<int> >mp;
int ans[N];
void solveB() {
    for(int i=1;i<=n;i++) {
        int p1,p2,len=s[i][0].size();
        for(int j=0;j<len;j++) {
            if(s[i][0][j]=='b')p1=j;
            if(s[i][1][j]=='b')p2=j;
        }
        a[i]={p1-p2,p1-1,len-p1,len,i};
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=q;i++) {
        int p1,p2,len=t[i][0].size();
        for(int j=0;j<len;j++) {
            if(t[i][0][j]=='b')p1=j;
            if(t[i][1][j]=='b')p2=j;
        }
        b[i]={p1-p2,p1-1,len-p1,len,i};
    }
    sort(b+1,b+q+1);
    int now=0;
    for(int i=1;i<=q;i++) {
        while(now<n&&a[now+1].pre<=b[i].pre) {
            now++;
            auto pos=lower_bound(mp[a[now].p].begin(),mp[a[now].p].end(),a[now].suf);
            mp[a[now].p].insert(pos,a[now].suf);
        }
        int p=upper_bound(mp[b[i].p].begin(),mp[b[i].p].end(),b[i].suf)-mp[b[i].p].begin();
        ans[b[i].id]=p;
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
}
ull base=20081023;
ull pw[M],hh1[M],hh2[M];
map<ull,map<ull,int> >buc;
ull query1(int l,int r) {
    if(!l)return hh1[r];
    else return hh1[r]-hh1[l-1]*pw[r-l+1];
}
ull query2(int l,int r) {
    if(!l)return hh2[r];
    else return hh2[r]-hh2[l-1]*pw[r-l+1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    bool flg=1;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1],flg&=check(s[i][0])&&check(s[i][1]);
    for(int i=1;i<=q;i++)
        cin>>t[i][0]>>t[i][1],flg&=check(t[i][0])&&check(t[i][1]);
    if(flg)return solveB(),0;
    for(int i=1;i<=n;i++) {
        ull h1=0,h2=0;int len=s[i][0].size();
        for(int j=0;j<len;j++) {
            h1=h1*base+s[i][0][j];
            h2=h2*base+s[i][1][j];
        }
        buc[h1][h2]++;
        //cerr<<h1<<' '<<h2<<'\n';
    }
    //return 0;
    pw[0]=1;
    for(int i=1;i<M;i++)pw[i]=pw[i-1]*base;
    for(int i=1;i<=q;i++) {
        int l=100000000,r=0,len=t[i][0].size();
        hh1[0]=t[i][0][0];
        hh2[0]=t[i][1][0];
        for(int j=0;j<len;j++) {
            if(t[i][0][j]!=t[i][1][j])l=min(l,j),r=j;
        }
        for(int j=1;j<len;j++)
            hh1[j]=hh1[j-1]*base+t[i][0][j],
            hh2[j]=hh2[j-1]*base+t[i][1][j];
        //c/err<<l<<' '<<r<<'\n';
        int ans=0;
        for(int j=0;j<=l;j++) {
            for(int k=r;k<len;k++) {
                //cerr<<"qwq\n";
                //cerr<<j<<' '<<k<<' '<<query1(j,k)<<' '<<query2(j,k)<<'\n';

                ans+=buc[query1(j,k)][query2(j,k)];
                //cerr<<"ewe\n";
            }
        }
        //cerr<<"qwq\n";
        printf("%d\n",ans);
    }
    return 0;
}
