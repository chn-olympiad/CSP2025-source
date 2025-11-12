#include<bits/stdc++.h>
#define pss pair<string ,string>
using namespace std;
const int maxn=1e5+5;
map<pair<string,string>,bool>vis;
string s1,s2,t1,t2;
pss a[maxn];
bool sz[maxn];
int n,q,mx,f[2*maxn][maxn/100][2],t[2*maxn];
bool cmp(pss aa,pss bb){
    return aa.first.size()<bb.first.size();
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        vis[make_pair(s1,s2)]=1;
        sz[s1.size()]=1;
        mx=max(mx,(int)s1.size());
        a[i]={s1,s2};
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        t[i]=a[i].first.size();
        int h=s1.find('b'),g=s2.find('b'),c;
        c=abs(h-g);
        f[i][c][0]=f[i-1][c][0];
        f[i][c][1]=f[i-1][c][1];
        f[i][c][h>g]++;
    }
    if(q==1){
        int st,ans=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n";
            return 0;
        }
        st=t1.size()-1;
        for(int i=1;i<=n;i++){
            if(t1.find(a[i].first)<=st){
                if(t2.find(a[i].second)<=st){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    while(q--){
        int st;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n";
            continue;
        }
        st=t1.size()-1;
        int i=0,j=st;
        while(t1[i]==t2[i])i++;
        while(t2[j]==t1[j])j--;
        if(j-i+1>mx){
            cout<<"0\n";
            continue;
        }
        if(i==0&&j==st){
            cout<<vis[make_pair(t1,t2)]<<"\n";
            continue;
        }
        int ans=0;
        string k1="",k2="";
        for(int l=i+1;l<=j-1;l++)k1+=t1[l],k2+=t2[l];
        ans+=vis[make_pair(k1,k2)];
        if(i==j){
            k1=t1[i],k2=t2[i];
            ans+=vis[make_pair(k1,k2)];
            i--,j++;
        }
        if((i+1)*(st-j+1)<=600000){
            for(;i>=0;i--){
                k1=t1[i]+k1,k2=t2[i]+k2;
                string d1=k1,d2=k2;
                for(int l=j;l<=st;l++){
                    d1+=t1[l],d2+=t2[l];
                    ans+=vis[make_pair(d1,d2)];
                    if(d1.size()>mx)break;
                }
                if(k1.size()>mx)break;
            }
            cout<<ans<<"\n";
            continue;
        }else{
            i=t1.find('b'),j=t2.find('b');
            int op=upper_bound(t+1,t+1+n,t1.size())-t-1;
            cout<<f[op][abs(i-j)][i>j]<<"\n";
        }
        
    }
    
    return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/