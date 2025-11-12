#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n,k,cnt;
int a[N];
bool b[N];

int checkk(int e,int f)
{
	for(int i=e;i>=f;i--)
	{
		if(b[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int uuu;
		cin>>uuu;
		if(uuu==k)
		{
			cnt++;
			b[i]=1;
		}
		a[i]=uuu^a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int kb=checkk(j,j-i);
			if(kb!=-1)
			{
				j=kb+i+1;
			}
			if(j>n)
			{
				break;
			}
			int p=a[j]^a[j-i];
			if(p==k)
			{
				cnt++;
				for(int r=j-i;r<=j;r++)
				{
					b[r]=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}