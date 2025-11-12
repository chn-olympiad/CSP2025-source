#include <bits/stdc++.h>
using namespace std;
int seat[121],n,m,self,r,c,ma[11][11],num=1,num2,num3;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    num3=n*m;
    for(int i=1;i<=n*m;i++)cin>>seat[i];
    self=seat[1];
    sort(seat+1,seat+n*m+1);// 1 2 3 4
    for(int i=n*m;i>=1;i--)if(seat[i]<self)num3--;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)ma[i][j]=num++;
    for(int i=2;i<=m;i+=2){
        num2=n;
        for(int j=1;j<=n/2;j++)swap(ma[i][j],ma[i][num2--]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ma[i][j]==num3){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
