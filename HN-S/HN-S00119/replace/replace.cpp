#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define ull unsigned long long
#define base 1145141

int n,q;
string s[200005][2],t[2];
ull H_s[200005][2],H[5000005][2],fac[5000005];
inline ull get(rint l,rint r,rint x){
    return H[r][x]-H[l-1][x]*fac[r-l+1];
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fac[0]=1;
    for(rint i=1;i<=5000000;i++)fac[i]=fac[i-1]*base;
    cin>>n>>q;
    for(rint i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        for(rint j=0;j<s[i][0].size();j++){
            H_s[i][0]=H_s[i][0]*base+s[i][0][j];
            H_s[i][1]=H_s[i][1]*base+s[i][1][j];
        }
    }
    while(q--){
        cin>>t[0]>>t[1];
        rint l=t[0].size()-1,r=0,len=0,res=0;
        for(rint i=1;i<=t[0].size();i++){
            H[i][0]=H[i-1][0]*base+t[0][i-1];
            H[i][1]=H[i-1][1]*base+t[1][i-1];
            if(t[0][i-1]!=t[1][i-1])l=min(l,i-1),r=max(r,i-1);
        }
        len=r-l+1;
        for(rint i=1;i<=n;i++){
            for(rint j=0;j+len-1<s[i][0].size();j++){
                rint pl=l-j,pr=r+(s[i][0].size()-(j+len));
                pl++,pr++;
                if(pl<1||pr<1||pl>t[0].size()||pr>t[0].size())continue;
                if(get(pl,pr,0)==H_s[i][0]&&get(pl,pr,1)==H_s[i][1])res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}