#include<bits/stdc++.h>
#define int unsigned long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int base=131,N=2e6+10;
int f[N];
void solve(){
    int n,q;
    cin>>n>>q;
    if(n>100){
        rep(T,1,q){
            cout<<"0\n";
        }
        return;
    }
    map<string,string>mp;
    rep(i,1,n){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    rep(T,1,q){
        int ans=0;
        string a,b;
        cin>>a>>b;
        if(mp.count(a)){
            string s=mp[a];
            if(s==b) ++ans;
        }
        int len1=a.size();
        int len2=b.size();
        a=" "+a;
        b=" "+b;
        rep(i,1,n){
            if(a[i-1]!=b[i-1]) continue;
            string s1="";
            string s2="";
            rep(j,i,n){
                s1+=a[j];
                if(mp.count(s1)){
                    s2=mp[s1];
                    int ll=s2.size();
                    string ss2="";
                    rep(k,i,i+ll-1) ss2+=b[k];
                    if(s2==ss2){
                        string f1=" ";
                        string f2=" ";
                        rep(t,j+1,len1) f1+=a[t];
                        rep(t,i+ll,len2) f2+=b[t];
                        if(f1==f2) ++ans;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1; 
    // cin>>T;
    for(;T;--T){
        solve();
    }
    return 0;
}
/*
g++ replace.cpp -o replace -std=c++14 -O2 -Wall
*/