#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],k=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];if(a[i]>a[1])k++;
	}c=k/n+1;
	if(k%(2*n)<=n)r=k%(2*n);
	else r=n-k%n+1;
	if(n==1&&m==1)c=1,r=1;
	else if(n==1)c=k,r=1;
	else if(m==1)c=1,r=k;
	cout<<c<<" "<<r;
	return 0;
} 
