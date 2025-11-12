#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=(1e+5)*5+10;
int a[N];
int solve(int l,int r)
{
	int sum=a[l];
	for(int i=l+1;i<=r;i++)
	{
		sum=sum^a[i];
	}
	return sum;
}
int main()
{
	freopen("stdin.xor","r",stdin);
	freopen("stdout.xor","w",stdout);
	int n,k,ans=0;
	int l=1,r=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(solve(l,r)==k)
		{
			ans++;
			l=r+1;
			r=l;
		}
		else
		{
			r++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
