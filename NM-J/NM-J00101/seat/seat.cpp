#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,b,c,d;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=m*n;i++)
    cin>>a[i];
    b=a[1];
sort(a+1,a+1+m*n);
for(int i=1;i<=m*n;i++)
    if(b==a[i]) c=i;
d=m*n-c+1;
if(d<=n) cout<<1<<' '<<d;
   else if(d%n==0) {
           if(d/n%2==0) cout<<d/n<<' '<<1;
              else cout<<d/n<<' '<<n;
   }
           else if(d/n%2==0) cout<<d/n+1<<' '<<d%n;
                   else cout<<d/n+1<<' '<<n-d%n;
cout<<endl;
cout<<c<<' '<<d;
return 0;}


/*2 2
99 100 97 98

2 2
98 99 100 97*/
