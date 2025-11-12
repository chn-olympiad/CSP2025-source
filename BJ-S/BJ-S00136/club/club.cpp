#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
int T,n,l,r,ans,a[100005][5],ls[100005],f[205][105][105];
bool f2,f3;
inline void wk(){
    ans=0;
    f2=f3=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if(a[i][1]!=0){
            f2=0;
        }
        if(a[i][2]!=0){
            f3=0;
        }
    }
    if(f2&&f3){
        for(int i=1;i<=n;i++){
            ls[i]=a[i][0];
        }
        sort(ls+1,ls+1+n);
        for(int i=n;i>(n/2);i--){
            ans=ans+ls[i];
        }
        cout << ans << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                int h=i-j-k;
                if(h>n/2||h<0){
                    continue;
                }
                f[i][j][k]=0;
                if(h!=0){
                    f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][2]);
                }
                if(j!=0){
                    f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][0]);
                }
                if(k!=0){
                    f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][1]);
                }
                ans=max(ans,f[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        wk();
    }
    return 0;
}
