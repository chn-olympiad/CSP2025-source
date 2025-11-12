#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int bs=13331,N=2005;
int pw[N],hx[2][N];
unordered_map<int,int> mp;
int hs(string s){
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans*bs+s[i];
    }
    return ans;
}
int gt(int l,int r,int op){
    return hx[op][r]-hx[op][l-1]*pw[r-l+1];
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0]=1;
    for(int i=1;i<=2000;i++){
        pw[i]=pw[i-1]*bs;
    }
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        mp[hs(a)]=hs(b);
        // cout<<hs(a)<<" "<<hs(b)<<"****\n";
    }
    for(int i=1;i<=q;i++){
        string s,t;
        cin>>s>>t;
        int n=s.size();
        s="_"+s;
        t="_"+t;
        int ans=0;
        for(int i=1;i<=n;i++){
            hx[0][i]=hx[0][i-1]*bs+s[i];
            hx[1][i]=hx[1][i-1]*bs+t[i];
        }
        // cout<<hx[0][n]<<" "<<gt(1,n,0)<<"***\n";
        for(int l=1;l<=n;l++){
            if(gt(0,l-1,0)!=gt(0,l-1,1)) continue;
            for(int r=l;r<=n;r++){
                if(r!=n&&gt(r+1,n,0)!=gt(r+1,n,1)) continue;
                int tmp=gt(l,r,0),tmp2=gt(l,r,1);
                // if(i==1)cout<<l<<" "<<r<<" "<<tmp<<" "<<tmp2<<"****\n";
                if(mp.count(tmp)){
                    if(mp[tmp]==tmp2) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}