#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,jx;
int nm[500001];
int xrn[500001];
int xr(int a,int b)
{
	if(a==b) return nm[a];
	else return (xrn[a-1] xor xrn[b]);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nm[i]);
		xrn[i]=(xrn[i-1] xor nm[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(xr(i,j)==k) 
			{
				i=j;
				jx++;
				break;
			}
			
		}
	}
	cout<<jx;
	return 0;
 } 
