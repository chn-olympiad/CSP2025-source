#include<bits/stdc++.h>
using namespace std;
int a[500009];
int n,m;
int f(int x)
{
	if(x==n-1)
	{
		if(a[x]==m)
			return 1;
		else
			return 0;
	}
	if(a[x]==m)
		return f(x+1)+1;
	int i,j=a[x];
	for(i=x+1;i<n;i++)
		{
			j^=a[i];
			if(j==m)
			{
				return f(i+1)+1; 
				break;
			}
		}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,ans=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)
	{
		int op=f(i);
		ans=max(ans,op);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
