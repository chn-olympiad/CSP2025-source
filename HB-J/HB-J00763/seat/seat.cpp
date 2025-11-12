#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
int x=a[1];
sort(a+1,a+n*m+1,cmp);
int sum;
for(int i=1;i<=n*m;i++){
	if(a[i]==x){
		sum=i;
	}
}
int c,r;
if(sum%n==0){
	c=sum/n;
}
else if(sum%n!=0){
	c=(sum-sum%n)/n+1;
}
cout<<c<<" ";
if(c%2==0){
	r=n-sum%n+1;
}
else if(c%2!=0){
	if(sum%n==0){
		r=n;
	}
	else{
		r=sum%n;
	}
}
cout<<r;
return 0;
}
