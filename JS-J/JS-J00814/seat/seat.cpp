#include<bits/stdc++.h>
using namespace std;
int a[1010];
int n,m;
bool c(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int sum=n*m;
    int f=0;
    for(int i=0;i<sum;i++){
        cin>>a[i];
    }
    int cnt=1;
    for(int i=1;i<sum;i++){
        if(a[i]>a[0]){
            cnt++;
        }
    }
    if((cnt/m+1)%2==0){
        if(cnt%m==0){
            printf("%d %d",cnt/m,m-(cnt%m));
        }
        else{
            printf("%d %d",cnt/m+1,m-(cnt%m)+1);
        }
    }
    else{
        if(cnt%m==0){
            printf("%d %d",cnt/m,cnt%m);
        }
        else{
            printf("%d %d",cnt/m+1,cnt%m);
        }
    }
    return 0;
}
