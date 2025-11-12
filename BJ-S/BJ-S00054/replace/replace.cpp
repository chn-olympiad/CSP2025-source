#include<bits/stdc++.h>
#define ll long long
void read(int &x){
    x=0;bool neg=0;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=1;c=getchar();}
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(neg)x=-x;
}
#define se second
#define fi first
#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read2(x,y),read(z)
using namespace std;
int n,q,f[1005][1005][2];
string s[1005][2],t[2];
void slv(){
    read2(n,q);
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        for(int j=1;j<s[i][0].size();j++){
            f[i][j][0]=f[i][j-1][0];
            while(f[i][j][0]&&s[i][0][j]!=s[i][0][f[i][j][0]])f[i][j][0]=f[i][f[i][j][0]][0];
            f[i][j][1]=f[i][j-1][1];
            while(f[i][j][2]&&s[i][1][j]!=s[i][1][f[i][j][1]])f[i][j][1]=f[i][f[i][j][1]][1];
        }
    }
    while(q--){
        cin>>t[0]>>t[1];
        if(t[0].size()!=t[1].size()){
            puts("0");continue;
        }
        int l=0,r=t[0].size()-1;
        // cout<<l<<" "<<t[0].size()<<" "<<(l<t[0].size())<<" "<<t[0][l+1]<<" "<<t[1][l+1]<<endl;
        while(l<((int)t[0].size())&&t[0][l]==t[1][l]){
            l++;
        }
        while(r>=0&&t[0][r]==t[1][r])r--;
        // cout<<l<<" "<<r<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            int k0=0,k1=0;
            for(int j=0;j<=t[0].size();j++){
                while(k0&&t[0][j]!=s[i][0][k0])k0=f[i][k0-1][0];
                if(t[0][j]==s[i][0][k0])k0++;
                while(k1&&t[1][j]!=s[i][1][k1])k1=f[i][k1-1][1];
                if(t[1][j]==s[i][1][k1])k1++;
                // cout<<l<<" "<<r<<" "<<j-s[i][0].size()+1<<" "<<j<<endl;
                if(k0==s[i][0].size()&&k1==s[i][1].size()){
                    // cout<<l<<" "<<r<<" "<<j-s[i][0].size()+1<<" "<<j<<endl;
                    if(j>=r&&j-s[i][0].size()+1<=l)
                    ans++;
                }
                if(k0==s[i][0].size()){
                    k0=f[i][k0-1][0];
                }
                if(k1==s[i][1].size()){
                    k1=f[i][k1-1][1];
                }
            }
        }
        cout<<ans<<endl;
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    slv();
}   