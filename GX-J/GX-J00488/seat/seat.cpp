#include<bits/stdc++.h>
using namespace std;
long long a[11][11];
int main(){
  //  freopen("seat.in","r",stdin);
   // freopen("seat.out","w",stdout);
    int a[0];
    int n,m,b;
    cin>>n>>m>>b;
    for(int i=1;i<=m*n-1;i++)
        {
    cin>>a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=1;i<=m*n-1;i++)
    {
        if(b==a[i-1]&&b==a[i+1])
        {
        int c=i/n,r=i/n;
        cout<<c<<" "<<r;

        }
    }
    return 0;
}














