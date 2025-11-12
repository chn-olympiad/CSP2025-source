#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m;
cin>>n>>m;
long long hh=n*m;
long long a[hh];
for(int i=1;i<=hh;i++){
        cin>>a[i];
}
int yy=a[1];
sort(a+1,a+hh+1);
long long op=0;
for(int i=hh;i>=1;i--){
    op++;
    if(a[i]==yy) break;
}
cout<<(op+n-1)/n<<" ";
if(((op+n-1)/n)%2==0)
{
    cout<<n-(op%n)+1;
}
else{
        if(op%n!=0)
    cout<<op%n;
else cout<<n;
}
return 0;
}
