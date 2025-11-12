#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],lrx=1,ans;
int start[N];
struct LR
{
	int l,r;
}lr[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int xorx=a[i];
		int x=i;
		start[i]=lrx;
		while(true)
		{
			if(xorx==k)
			{
				lr[lrx].l=i;
				lr[lrx].r=x;
				lrx++;
				break;
			}
			if(x>n)
			{
				break;
			}
			x++;
			xorx=xorx xor a[x];
		}
	}
	int start_lr=1;
	while(lr[start_lr].l<lr[1].r)
	{
		start_lr++;
	}
	int before=1;
	for(int i=1;i<=start_lr;i++)
	{
		before=i;
		int sum=1;
		for(int j=i+1;j<=lrx-1;j++)
		{
			if(lr[j].l>lr[before].r)
			{
				sum++;
				before=j;
			}
		}
		ans=max(ans,(long long)sum);
	}
	cout<<ans;
	return 0;
}