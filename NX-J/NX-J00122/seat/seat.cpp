#include <bits/stdc++.h>
using namespace std;
int a[9999];
int s,d,y,n,m;
int main(){
        freopen("seat2.in","r",stdin);
    freopen("seat.out","w",stdout);
cin>>s>>d;
for(int i=1;i<=s*d;i++){
cin>>a[i];
}
 m=a[1];
for(int i=1;i<=s*d;i++){
for(int j=1;j<=s*d;j++){
if(a[j]<a[j+1]){
swap(a[j],a[j+1]);
}
}
}
int f=s*d;
for(int i=1;i<=s*d;i++){
if(a[i]==m)
    y=i;
}
if(y%d!=0){
n=y/s+1;
}
else{
   n=y/s;
}
if(n%2!=0)
cout<<n<<" "<<y%d;
else
    cout<<n<<" "<<s-y%d+1;
return 0;
}

