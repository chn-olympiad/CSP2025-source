/*
100 pts expected

while(1){
    rp+=inf;
}
pls let me pass
i want 1st prize
plllllllllllllllllllsssssssssssssssssssss
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],R;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    //x:i/m y:i%m
    for(int i=1;i<=n*m;i++){
        int x=(i-1)/n+1,y=i%n;
        if(y==0) y=n;
        if(x%2==0) y=n-y+1;
        if(a[i]==R){
            printf("%d %d",x,y);
            return 0;
        }
    }
    return 0;
}
//touch to enter texts...
