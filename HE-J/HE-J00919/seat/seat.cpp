#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,a[10000],num=0,c=0,d=0;
cin>>m>>n;
for(int i=1;i<=m*n;i++){
cin>>a[i];
}
for(int i=1;i<=m*n;i++){
if(a[1]<a[i]){
num++;
}
}
num+=1;
if(num<=n){
c=1;
d=num;
}else if((num/n)%2==0){
c=num/n+1;
d=num%n;
}else if((num/n)%2!=0)
c=num/n+1;
d=n-(num%n);
cout<<c<<" "<<d;
fclose(stdin);
fclose(stdout);
return 0;
}
