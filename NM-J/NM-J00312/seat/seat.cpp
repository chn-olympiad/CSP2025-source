#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,arr[N],a1,num=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    for(int i=1,x;i<n*m;i++)cin>>x,num=x>a1?num+1:num;
    cout<<((num/m)+(num%m?1:0))<<' '<<((num%(2*m)>m)?m-(num%m)+1:(num%m)?(num%m):m);
}
