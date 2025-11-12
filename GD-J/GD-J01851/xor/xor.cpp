#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100010];
int sum;
void xorr(int x,int y)
{
	int cnt=a[x];
	for(int i=x+1;i<=y;++i)
	{
		cnt=cnt^a[i];
	}
	if(cnt==k)
	{
		sum++;
	
	if(y<n)
	{
		xorr(y+1,y+1);
	}
	else
	{
		cout<<sum;
		return;
	}
	}
	else if(y<n)
	{
		xorr(x,y+1);
	}
	else
	{
		xorr(x+1,x+1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	xorr(1,1);
	return 0;
}

