#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,k,a[N],flag=1,cnt=0,vis[N]={0};
int sum(int s,int e)
{	int num=a[s];
	for(int i=s;i<e;i++)
	{	num^=a[i+1];
		if(vis[i])
			return -1;
	}
	return num;
}
void solve()
{	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	cnt=0,flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		if(a[i]!=1)
			flag=false;
	}
	if(flag&&k==0)
	{	if(n%2==0)
			cout<<"1\n";
		else
			cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{	if(vis[i])
				break;
			else if(vis[j])
				continue;
			if(j==i&&a[i]==k)
			{	cnt++;
				vis[i]==1;
				//cout<<i<<" "<<j<<"\n";
				break;
			}
			else if(sum(i,j)==k)
			{	cnt++;
				for(int ii=i;ii<=j;ii++)
					vis[ii]=1;
				//cout<<i<<" "<<j<<"\n";
				break;
			}
		}
	//for(int i=1;i<=n;i++)
	//	cout<<vis[i]<<" ";
	//cout<<"\n";
	cout<<cnt<<"\n";
}
int main()
{	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
//DeBruyne rp++
