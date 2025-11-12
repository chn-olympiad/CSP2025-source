#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	int x=1;
	for(int i=1;i<=n;i++)x*=i;
	return x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxn=0,s=0;
	cin>>n;
	int a[n+1];
	bool f1=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i]; 
		if(a[i]>=maxn)maxn=a[i];
		if(a[i]!=1)f1=false;
	}
    if(n<3)cout<<sum;
    if(n==3){
    	if(s>maxn*2)sum=1;
    	else sum=0;
	}
	if(f1){
		int x=f(n);
		int x1=f(2);
		for(int j=3;j<=n;j++){
			x1*=j;
			sum+=x/x1;
		}
	}
	cout<<sum;
	return 0;
}
