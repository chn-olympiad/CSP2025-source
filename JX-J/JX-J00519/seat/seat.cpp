#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m,sum,ww,q,a[103],b[13][13];
cin>>n>>m;
for(long long i=1;i<=n*m;i++){
        cin>>a[i];
}sum=a[1];
sort(a+1,a+1+n*m);
for(long long i=n*m,j=1;i>=1;i--,j++){
    if(a[i]==sum)ww=j;
}
q=ww/n;
if(ww%n==0){
   cout<<q<<" ";
   if((q-1)%2==0)cout<<n;
else cout<<1;
}else{
cout<<q+1<<" ";
if(q%2==0)cout<<ww%n;
else cout<<n+1-ww%n;
}
fclose(stdin);
fclose(stdout);
return 0;
}
//1 2 2 1
//0   1
