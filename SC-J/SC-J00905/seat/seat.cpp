#include<bits/stdc++.h>
using namespace std;
int n,m,num,sum,a[100],c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==num){
			sum=n*m-i+1;
			break;
		}
	if(sum%n!=0){
		c=sum/n+1;
		if(c%2!=0)
			r=sum%n;
		else
			r=n-sum%n+1;
	}
	else{
		c=sum/n;
		if(c%2!=0)
			r=n;
		else
			r=1;
	}
	cout<<c<<' '<<r;
	return 0;
}
