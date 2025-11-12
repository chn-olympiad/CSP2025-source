#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)  
	{
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int l=0,r=100,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==x)
		{
			ans=mid;
			break;
		}
		else if(a[mid]>x) l=mid+1;
		else r=mid-1;
	}
	for(int i=1;i<=n;)
	{
		for(int j=1;j<=m;)
		{
			++cnt;
			if(cnt==ans)
			{
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
			else if(j&1) 
			{
				if(i==n) ++j;
				else ++i;
			}
			else
			{
				if(i==1) ++j;
				else --i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
