#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int t;
int tin;
int sum;
int sum1; 
int a[105];
int main(){
	cin>>n>>m;
	tin=n*m; 
	for(int i=1;i<=tin;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=tin;i++)
	{
		if(a[1]<a[i])
		{
			t++;
		}
	}
	sum=(t-t%n)/n+1;
	sum1=t%n+1;
	if(sum%2==0)
	{
		cout<<sum<<" "<<n-t%n;
	}else{
		cout<<sum<<" "<<sum1;
	}


	
	return 0;
} 
