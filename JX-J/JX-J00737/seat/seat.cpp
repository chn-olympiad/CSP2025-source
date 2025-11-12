#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int s=a[1];
    sort(a+1,a+n*m+1);
    int t;
    for(int i=n*m,j=1;i>=1;i--,j++){
        if(a[i]==s){
            t=j;
            break;
        }
    }
    int x=t/n;
    if(x*n<t) x++;
    int y=t-(x-1)*n;
    if(y==0) y=n;
    if(x%2==0) y=n-y+1;
    cout<<y<<" "<<x;
    return 0;
}
