#include<bits/stdc++.h>
using namespace std;
int a[500010];
map<int,int> vis;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,ans=0,x=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)
		{
			vis[i]++;
			ans++;
		}			
	}	
	for(int l=1,cnt=1;l<=n;l+=x+1,cnt++)
	{	
		int r=l+x,sum=a[l];
		if(r>n)
			break;
		for(int i=l+1;i<=r;i++)
		{
			sum^=a[i];
		}
		if(sum==k)
		{		
			for(int i=1;i<=r;i++)
			{
				if(vis[i])
				{
					if(i==l||i==r||i>l||i<r)
						ans--;
				}
			}
			ans++;
		}
		if(r==n)
		{
			l=0;
			x++;
		}	
			
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 2
2 1 0 3
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
