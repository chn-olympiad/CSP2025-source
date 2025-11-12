#include<bits/stdc++.h>
using namespace std;
int n,m,a,a1,b=0,tong[105];
int main(){
    freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    tong[a1]++;
    for(int i=1;i<=n*m-1;i++){
        cin>>a;
        tong[a]++;
    }

    int i=100;
    while(b<=n*m){
        if(tong[i]==1)b++;
        if(i==a1)break;
        i--;
    }

    int t=b;
    int n1,m1=(t-1)/n+1;
    b%=2*n;
    if(b>n)n1=(2*n-b)+1;
    else n1=b;
    cout<<m1<<" "<<n1;
return 0;
}
