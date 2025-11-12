#include <bits/stdc++.h>
using namespace std;
int n,maxn=0;
unsigned long long q[500005],l,k,o;
int diff[500010]={};
/*0 0 0
 * 0 0 0
 * 
 * 1 0 0
 * 1 -1 0
*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			l=0;
			int flag=1;
			for(int ll=i;ll<=j;ll++)
			{
				l^=q[ll];
				if(diff[ll])
				{
					flag=0;
					break;
				}
			}
			if(l==k&&flag)
			{
				maxn++;
				for(int ll=i;ll<=j;ll++)
				{
					diff[ll]=1;
				}
			}
			//diff[j]--;
			//diff[i]++;
		}
	}
	cout<<maxn;
	return 0;
}
