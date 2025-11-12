#include <bits/stdc++.h>
using namespace std;
map < int ,map < int , map < int , int > > > f;
int a[100005][5];
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
		f.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int ans=0;
        for(int i=1,l=0;i<=n;i++,l=!l){
            for(int j=0;(j<=n/2);j++){
                for(int k=min(i,n/2);(k>=0)&&((i-j-k)<=n/2);k--){
                    if(j>=1)f[l][j][k]=max(f[l][j][k],f[!l][j-1][k]+a[i][1]);
                    if(k>=1)f[l][j][k]=max(f[l][j][k],f[!l][j][k-1]+a[i][2]);
                    if((i-j-k)>=1)f[l][j][k]=max(f[l][j][k],f[!l][j][k]+a[i][3]);
                    ans=max(ans,f[l][j][k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
