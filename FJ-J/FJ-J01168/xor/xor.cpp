#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int maxnum=0,idx;
int w[N],s[N];
bool st[N];
int n;
long long k;
void find(int x)
{
	if(x==n+1) return; 
	for(int i=x;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int y=s[i-1] xor s[j];
			if(y==k)
			{
				idx++;
				find(j+1);
				maxnum=max(maxnum,idx);
				idx=0;
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		s[i]=s[i-1] xor w[i];
	}
	find(1);
	cout<<maxnum;
	return 0;
}
