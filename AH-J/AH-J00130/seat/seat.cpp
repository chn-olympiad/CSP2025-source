#include<iostream>
#include<algorithm>
using namespace std;
int n,m,cnt,a[105],b[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++cnt];
        }
    }
    int flag=a[1];
    sort(a+1,a+cnt+1,cmp);
    int ans=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=a[++ans];
            }
        }else{
            for(int i=n;i>=1;i--){
                b[i][j]=a[++ans];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(flag==b[i][j]){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
