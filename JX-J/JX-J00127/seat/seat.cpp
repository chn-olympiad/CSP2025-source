#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],k,o,kk,sz;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int j=n*m;j>=1;j--){
	if(k==a[j]){
		o=sz+1;
	break;
}
else
sz++;
}
kk=o/n;
if(o%n!=0)
kk++;
if(kk%2==0)
cout<<kk<<" "<<n-o%n+1;
else{
if(kk>1)
cout<<kk<<" "<<o%n;
else
cout<<kk<<" "<<o;
}
}
