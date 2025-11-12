#include<bits/stdc++.h>
using namespace std;
int a[5005],n,c;
long long ans=0;
void f(int x,int sum,int num,int b,int d)
{
	c=0;
	if(b==1 && num>=3 && sum>a[x]*2) c=1;
	if(num==n){
		if(ans=0) ans=d;
		if(d>ans) ans=d;
		return ;
	}
	else if(sum>=a[x+1]){
		f(x+1,sum+a[x+1],num+1,1,d+c);
		f(x+1,sum,num,0,d+c);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<n;j++)
			f(j,a[i]+a[j],2,0,0);
	}
	cout<<ans;
	
	return 0;
}
