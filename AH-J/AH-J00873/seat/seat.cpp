#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,r,a[N],k=1,j=0;
int cnt,f,ansx,ansy,ans;
int dis[15][15];
int main(){
    freopen("seat.in","r".stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    ans=a[1];
    sort(a+1,a+(n*m)+1,greater<int>());
    while(cnt<=n*m){
        j++;
        if(k==1&&f==0){
            f=1;
            for(int i=1;i<=n;i++)
                dis[i][j]=a[++cnt];
            k=n;
        }
        if(k==n&&f==0){
            for(int i=n;i>=1;i--)
                dis[i][j]=a[++cnt];
            k=1;
        }
        f=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[i][j]==ans){
                ansx=i;
                ansy=j;
                break;
            }
        }
    }
    printf("%d %d",ansy,ansx);
    return 0;
}
