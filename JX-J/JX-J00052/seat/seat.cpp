#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
int ans=1,b=0;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
for(int i=1;i<=n*m;i++){
    if(a[i]>a[1])
        ans++;
}
int c=ans%n;
if(c==0){
    b=ans/n;
    c=n;
}else{
b=ans/n+1;
}
if(b%2==0){
    c=n+1-c;
}else{
c=c;
}
cout<<b<<" "<<c;
return 0;
}

