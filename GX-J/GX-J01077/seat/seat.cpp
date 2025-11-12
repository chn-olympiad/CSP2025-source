#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,b,c,d,e,f,g,m,a[100000];b=0;c=0;e=0;f=0;g=0;d=0;
cin>>n>>m;
for(int i=0;i<n*m;i++){
    cin>>a[i];
}
d=a[0];
for(int j=0;j<=n*m;j++){
for(int i=0;i<n*m;i++){
    if(a[i]<a[i+1]){
        b=a[i];
        c=a[i+1];
        a[i]=c;
        a[i+1]=b;
        }
    }
}
for(int i=0;i<n*m;i++){
    if(a[i]==d){
        e=i;
    }
}
f=e/n;g=e%n;
f=f+1;
if(g==0){
g=1;
}
if(f%2==0){
    cout<<f<<' '<<n-g;
}
if(f%2!=0){
    cout<<f<<' '<<g;
}
return 0;
}
