#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],book[100005],ans=0;
vector<int> q[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			book[i]++;
			ans++;
			continue;
		}
		for(int j=i;j<=n;j++)
		{
			int cc=a[i]^a[j];
			if(cc==k)
			{
				q[i].push_back(j);
				q[j].push_back(i);
			}
		}
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=0;i<int(q[t].size());i++)
		{
			cout<<q[t][i]<<" ";
		}
		cout<<endl;
	}
	for(int t=1;t<=n;t++)
	{
		int minn=2147483647,flag=0;
		for(int i=0;i<int(q[t].size());i++)
		{
			if(book[q[t][i]]!=1&&book[t]!=1)
			{
				int x=abs(t-q[t][i]);
				if(x<minn)
					minn=x,flag=1;
			}
		}
		if(flag==1)
		{
			ans++;
			for(int i=t;i<=minn;i++)
				book[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
/*
	for(int t=1;t<=n;t++)
	{
		for(int i=0;i<int(q[t].size());i++)
		{
			cout<<q[t][i]<<" ";
		}
		cout<<endl;
	}
*/
