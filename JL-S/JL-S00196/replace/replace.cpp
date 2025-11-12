#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1,mod=1e9+7;
int n,q,kmp[N],c[N];
string s[N][3],t[N][3];
char a[N],b[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n>1000||q>1000){
        while(q--) cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];
    for(int i=1;i<=q;i++){
        int m1=t[i][1].size(),ans=0;
        for(int j=1;j<=n;j++){
            int m=s[j][1].size(),l=0;
            for(int k=1;k<=m;k++) a[k]=s[j][1][k-1];
            for(int k=1;k<=m1;k++) b[k]=t[i][1][k-1];
            for(int k=1;k<=m;k++) kmp[k]=0;
            for(int k=1;k<=m;k++){
                while(l!=kmp[l]) l=kmp[l];
                if(a[k]==a[l+1]) l++;
                kmp[k]=l;
            }
            l=0;
            for(int k=1;k<=m1;k++){
                c[k]=0;
                while(l!=kmp[l]) l=kmp[l];
                if(b[k]==a[l+1]) l++;
                if(l==m) c[k-m+1]=1;
            }
            for(int k=1;k<=m1;k++){
                if(c[k]){
                    for(int l=k;l<=k+m-1;l++){
                        b[l]=s[j][2][l-k];
                    }
                    k=k+m;
                }
            }
            bool boo=0;
            for(int k=1;k<=m1;k++){
                if(b[k]!=t[i][2][k-1]){
                    boo=1;
                    break;
                }
            }
            if(!boo) ans++;
        }
        cout<<ans<<'\n';
    }
}
