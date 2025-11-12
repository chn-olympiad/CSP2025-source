#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105];
int n,m;
bool comp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&b[i]);
    }
    int num=b[1];
    sort(b+1,b+n*m+1,comp);
    int sum=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                sum++;
                a[j][i]=b[sum];
            }
        }
        else if(i%2==0){
            for(int j=n;j>=1;j--){
                sum++;
                a[j][i]=b[sum];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==num){
                printf("%d %d",j,i);
                break;
            }
        }
    }
    return 0;
}
