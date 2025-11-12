#include<bits/stdc++.h>
using namespace std;
int n,m,a[10][10];
int b[110]={0},cnt=1,sum;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cnt=n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            b[cnt]=a[i][j];
            cnt--;
            if(i==1&&j==1) sum=a[i][j];
        }
    }
    sort(b+1,b+n*m+1,cmp);
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=b[++cnt];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==sum){
                cout<<i<<" "<<j;
                break;
            }
            cnt++;
        }
    }
    return 0;
}
