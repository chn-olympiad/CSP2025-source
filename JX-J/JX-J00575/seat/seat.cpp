#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
    cin>>a[i];
    int p=1;
for(int i=2;i<=n*m;i++)
if(a[1]<a[i]) p++;
int x=p/n,y=(p-1)%n+1,l=0;
if(p%n!=0) l=1;
cout<<x+l<<' '<<y;
return 0;
}
