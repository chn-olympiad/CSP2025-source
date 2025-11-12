#include<bits/stdc++.h>
using namespace std;
 int T,a[100005][4];
 int b,c[4],g[6];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    int t=T;
    for(;T>0;T--){
        int d=20005,k=20005,n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                c[1]++;
                a[i][0]=a[i][1];
            }else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
                c[2]++;
                a[i][0]=a[i][2];
            }else{
                c[3]++;
                a[i][0]=a[i][3];
            }
        }
        for(int i=1;i<=3;i++){
            if(c[i]>n/2){
                int kx,dx;
                for(int j=1;j<=n;j++){
                    if(k>=a[j][i]/2){
                        k=a[j][i];
                        kx=j;
                    }
                }
                a[kx][i]=20005;
                for(int j=1;j<=n;j++){
                    if(d>=a[j][i]){
                        d=a[j][i];
                        dx=j;
                    }
               }
               a[kx][i]=k;
               if(a[dx][i]+a[kx][3]>a[dx][i]+a[kx][2]){
                    a[kx][0]=a[kx][3];
               }else if(a[dx][i]+a[kx][2]>a[dx][i]+a[kx][3]){
                   a[kx][0]=a[kx][2];
               }
                if(a[kx][i]+a[dx][3]>a[dx][i]+a[dx][2]){
                    a[kx][0]=a[kx][3];
               }else if(a[kx][i]+a[dx][2]>a[dx][i]+a[dx][3]){
                   a[dx][0]=a[dx][2];
               }
               g[T]--;
            }
        }
        for(int i=1;i<=n;i++){
            g[T]=g[T]+a[i][0];
        }
    }
    for(;t>0;t--){
        cout<<g[t]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
