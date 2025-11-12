#include<bits/stdc++.h>
using namespace std;
const int sb=998244353;
int a[114514],used[114514];
int ans,n;
void dfs(int no,int sum,int MAX,int last)
{
	int i,j,k;
	if(no>3)
	{
		if(sum>MAX*2) 
		{
			/*cout<<sum<<endl;
			for(i=1;i<=n;i++)
			{
				if(used[i]==1)
				{
					cout<<a[i]<<" ";
				}
			}
			cout<<endl;*/
			ans=(ans+1)%sb;
		}
	}
	for(i=last+1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=1;
			dfs(no+1,sum+a[i],max(MAX,a[i]),i);
			used[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i,j,k,m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];

	}
	sort(a+1,a+1+n);
	dfs(1,0,-0x3f3f3f3f,0);
	cout<<ans;
	return 0;
 }

