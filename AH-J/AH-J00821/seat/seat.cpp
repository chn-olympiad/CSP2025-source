#include<bits/stdc++.h>
using namespace std;
int a[105],cnt;
int f[12][12];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
///    for (int i=1;i<=n*m;i++){
///        cout<<a[i]<<' ';
///    }
///    cout<<" \n \n \n";
    int x(1),y(1);
    for (y=1;y<=m;y++){
        if(y%2){
            for(x=1;x<=n;x++){
                f[x][y]=a[++cnt];
//                printf("因为%d%2==%d，所以x=%d,y=%d,a[%d]=%d\n",y,y%2,x,y,cnt,a[cnt]);
            }
        }else{
            for(x=n;x>=1;x--){
                f[x][y]=a[++cnt];
//                printf("因为%d%2==%d，所以x=%d,y=%d,a[%d]=%d\n",y,y%2,x,y,cnt,a[cnt]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if(f[i][j]==t){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
