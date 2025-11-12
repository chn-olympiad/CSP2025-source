#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
typedef unsigned long long ull;
ull base=13331,p[M],h1[N],h2[N],ha[N],hb[N];
int n,q,sz[N];
string a,b;
inline ull get1(int l,int r){
    return (ha[r]-ha[l-1])*p[r-l+1];
}
inline ull get2(int l,int r){
    return (hb[r]-hb[l-1])*p[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    string s1,s2;
    p[0]=1;
    for(int i=1;i<M;i++) p[i]=p[i-1]*base;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        sz[i]=s1.size();
        for(int j=0;j<(int)s1.size();j++)
        h1[i]=h1[i]*base+s1[j]-'a'+1;
        for(int j=0;j<(int)s2.size();j++)
        h2[i]=h2[i]*base+s2[j]-'a'+1;
    }
    while(q--){
        cin>>s1>>s2;
        int ans=0;
        if(s1.size() != s2.size()) {cout<<0<<'\n';continue;}
        for(int i=1;i<=(int)s1.size();i++)
        ha[i]=ha[i-1]*base+s1[i-1]-'a'+1;
        for(int i=1;i<=(int)s1.size();i++)
        hb[i]=hb[i-1]*base+s2[i-1]-'a'+1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(int)s1.size();j++){
                if(get1(j,j+sz[i]-1)==h1[i] && get2(j,j+sz[i]-1)==h2[i]){
                    int flag=0;
                    for(int k=0;k<j;k++) if(s1[k]!=s2[k]) {flag=1;break;}
                    if(flag) continue;
                    for(int k=j+sz[i];j<=(int)s1.size();k++) 
                    if(s1[k]!=s2[k]) {flag=1;break;}
                    if(flag) continue;
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}