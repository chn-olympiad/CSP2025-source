#include<bits/stdc++.h>
using namespace std;
int n,x=0,ans;
long long k,a[5005],b[5005][5005];
pair<int,int> p[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(i==j)
				b[i][j]=a[i];
			else
				b[i][j]=(b[i][j-1])^(a[j]);
			if(b[i][j]==k)
			{
				p[i]={j,i};
				break;
			}
		}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		if(p[i].first==0)
			continue;
		else if(p[i].second>x)
		{
			ans++;
			x=p[i].first;
		}
	}
	cout<<ans;
	return 0;
}
