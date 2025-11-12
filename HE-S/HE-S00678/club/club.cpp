#include<bits/stdc++.h>
using namespace std;
long long n,t;long long n2;
long long a[100010][4],b[4];
long sum,ans;
void dfs(int id)
{
	if(id==n+1)
	{
		if(ans<sum)ans=sum;
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i]<n2)
		{
			sum+=a[id][i];
			b[i]++;
			id++;
			dfs(id);
			id--;
			b[i]--;
			sum-=a[id][i];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		n2=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		ans=sum=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
