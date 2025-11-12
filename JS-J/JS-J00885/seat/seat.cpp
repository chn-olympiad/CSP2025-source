#include <bits/stdc++.h>
using namespace std;
int a[15][15],m=1,n=1,b[105],q,t;
bool cmp(int a,int b){
return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    q=b[1];
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(q==b[i]){
            t=i;
            break;
        }
    }
    int y=(t-1)/n+1,x=(t-1)%n+1;
    if(y%2==0){cout<<y<<' '<<n+1-x;}
   if(y%2==1){cout<<y<<' '<<x;}
  }
