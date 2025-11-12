#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,k;
    int a[110];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            k=n*m-i+1;break;
        }
    }
    int k1=(k-1)%(2*n)+1;
    int x=(k1>n?2*n-k1+1:k1);
    int y=(k-1)/n+1;
    printf("%d %d\n",y,x);
}