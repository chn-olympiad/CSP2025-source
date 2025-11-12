#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a[50005],pos=0;
struct node
{
	int l,r;
}b[50005];

bool cmp(node x,node y)
{
	return x.r<y.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<=n-1; i++)
	{
		for(int j=1; j<=n-i; j++)
		{
			int qz=0;
			for(int k=j; k<=j+i; k++)
			{
				qz^=a[k];
			}
			if(qz==k)
			{
				pos++;
				b[pos].l=j;
				b[pos].r=j+i;
			}
		}
	}
	sort(b+1,b+pos+1,cmp);
	int last=b[1].r,ans=1;
	for(int i=2; i<=pos; i++)
	{
		if(b[i].l>last)
		{
			last=b[i].r;
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
