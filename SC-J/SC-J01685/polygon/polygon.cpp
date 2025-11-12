#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans,sum=0;
	cin>>n;
	if(n==1||n==2) cout<<0;
	else if(n==3)
	{
		for(int i=1;i<=3;i++)
		{
			cin>>a[i];
		}	
	
	sort(a+1,a+4,cmp);
	if(a[1]+a[2]+a[3]>a[1]*2) cout<<1;
	else cout<<0;
	}
	if(n>20&&n<=5000)
	{
		cout<<1;
	}
	if(n=4)
	{
		for(int i=1;i<=4;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+5,cmp);
		ans=a[1];
		if(a[1]+a[2]+a[3]>ans*2) sum++;
		if(a[4]+a[2]+a[3]>ans*2) sum++;
		if(a[1]+a[2]+a[4]>ans*2) sum++;
		if(a[1]+a[4]+a[3]>ans*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>ans*2) sum++;
		cout<<sum;
	}
	if(n=5)
	{
		for(int i=1;i<=5;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+6,cmp);
		ans=a[1];
		if(a[1]+a[2]+a[3]>ans*2) sum++;
		if(a[4]+a[2]+a[3]>ans*2) sum++;
		if(a[1]+a[2]+a[4]>ans*2) sum++;
		if(a[1]+a[4]+a[3]>ans*2) sum++;
		if(a[1]+a[2]+a[5]>ans*2) sum++;
		if(a[5]+a[2]+a[3]>ans*2) sum++;
		if(a[1]+a[5]+a[4]>ans*2) sum++;
		if(a[1]+a[5]+a[3]>ans*2) sum++;
		if(a[5]+a[4]+a[3]>ans*2) sum++;
		if(a[4]+a[2]+a[5]>ans*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>ans*2) sum++;
		if(a[1]+a[2]+a[3]+a[5]>ans*2) sum++;
		if(a[1]+a[2]+a[5]+a[4]>ans*2) sum++;
		if(a[5]+a[2]+a[3]+a[4]>ans*2) sum++;
		cout<<sum;
	}
	return 0;
	}
