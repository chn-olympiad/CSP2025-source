#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[10000]={},h;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i];
		}
	}
	h=a[1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]<a[i+1]){
				int d=a[i];
				a[i]=a[i+1];
				a[i+1]=d;
			}
		}
	}
	int e;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(h==a[i]){
				e=i;
				break;
			}
		}
	}
	int c,r;
	if(e%n==0){
		c=e/n;
	}
	else{
		c=e/n+1;
	}
	if(c%2!=0){
		if(e%c==0){
			r=n;
		}
		else if((e%c)==((e-1)%c)){
			r=(e-1)%c+1;
		}
		else{
			r=e%c;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

