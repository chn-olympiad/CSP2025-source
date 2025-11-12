#include<bits/stdc++.h>
using namespace std;
int n,m,r,f,a[10086];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)cin>>a[i];
r=a[1];
sort(a+1,a+n*m+1);
for(int i=1;i<=n*m;i++)if(a[i]==r)f=i;
f=n*m-f+1;
if(f%n==0){
if((f/n)%2==1)cout<<f/n<<" "<<n;
else cout<<f/n<<" "<<n-(f%n)+1;
}
else{
if((f/n+1)%2==1)cout<<f/n+1<<" "<<f-f/n*n;
else cout<<f/n+1<<" "<<n-(f%n)+1;
}
return 0;
}
