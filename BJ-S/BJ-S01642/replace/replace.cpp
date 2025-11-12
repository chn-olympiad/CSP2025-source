#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int N=2e5+10,M=5e6+10;
const ULL P=131;

int n,q;
struct PSS {
    ULL s1,s2; int len;
    friend bool operator < (PSS a,PSS b){
        return a.len<b.len;
    }
};
vector<PSS> a[30];
bool st[M],can[30];

ULL get(string &s){
    ULL res=0;
    for(int i=0;i<s.size();++i) res=res*P+s[i];
    return res;
}

bool check(){
    for(int i=0;i<26;++i) if(can[i]) return 1;
    return 0;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        string s1,s2; cin>>s1>>s2;
        a[s1[0]-'a'].push_back({get(s1),get(s2),(int)s1.size()});
    }
    for(int i=0;i<26;++i) sort(a[i].begin(),a[i].end());
    while(q--){
        string t1,t2; cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<26;++i) can[i]=1;
        int l=-1e9,r=1e9;
        for(int i=0;i<t1.size();++i){
            st[i]=(t1[i]!=t2[i]);
            if(st[i]){
                if(l==-1e9) l=i;
                r=i;
            }
        }
        LL Ans=0;
        for(int i=l;i>=0 && check();--i){
            int x=(int)(t1[i]-'a');
            int len=r-i+1;
            int j=lower_bound(a[x].begin(),a[x].end(),(PSS){0,0,len})-a[x].begin();
            if(j>=a[x].size()) can[x]=0;
            ULL h1=0,h2=0;
            int now=0,k=i;
            for(;j<a[x].size();++j){
                now=i+a[x][j].len-1; if(now>=t1.size()) break;
                for(;k<=now;++k) h1=h1*P+t1[k],h2=h2*P+t2[k];
                if(h1==a[x][j].s1 && h2==a[x][j].s2) Ans++;
            }
        }
        cout<<Ans<<endl;
    }
    return 0;
}