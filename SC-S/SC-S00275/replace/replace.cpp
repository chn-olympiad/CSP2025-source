#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
vector<int>v[200010];
string x[200010],y[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,q;
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		int sum=0;
		for(long long j=0;j<x[i].size();j++)
		{
			if(x[i][j]!=y[i][j]){
				sum++;
			}
		}
		v[sum].push_back(i);
	}
	if(q==1||n<=200)
	{
		while(q--)
		{
			string xx,yy;
			cin>>xx>>yy;
			int sum=0;
			for(int i=0;i<xx.size();i++)
			{
				if(xx[i]!=yy[i])sum++;
			} 
			long long ans=0;
			for(int j:v[sum])
			{
				for(int i=0;(i+x[j].size()-1)<xx.size();i++)
				{
					bool flag=1;
					for(int k=0;k<x[j].size();k++)
					{
						if(xx[i+k]!=x[j][k])flag=0;	
						if(yy[i+k]!=y[j][k])flag=0;	
						if(flag==0)break;
					} 
					if(flag)
					{
						ans++;	
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	else
	{
		while(q--)
		{
			cout<<0<<"\n";
		}
	}
	return 0;
} 