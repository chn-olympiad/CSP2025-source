#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
int n,k,a[N],b[N],ans;
pair<int,int> t[N];
bool flag1=1,flag[N];
vector<pair<int,int> >ve;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second-x.first<y.second-y.first;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)	flag1=false;
	}
	if(flag1)
	{
		if(k>1)
		{
			cout<<0;
		}
		else
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					sum++;
			if(k==0)
			{
				cout<<sum/2;
			}
			else
			{
				cout<<sum;
			}
		}
		exit(0);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i]^b[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int temp=b[j]^b[i-1];
				if(temp==k)
				{
//					cout<<i<<' '<<j<<' '<<b[i-1]<<' '<<b[j]<<' '<<temp<<'\n';
					ve.push_back(make_pair(i,j));
				}
			}
		}
//		cout<<'\n';
		for(int i=0;i<ve.size();i++)
		{
			t[i+1]=ve[i];
		}
		sort(t+1,t+ve.size()+1,cmp);
		for(int i=0;i<ve.size();i++)
		{
			ve[i]=t[i+1];
//			cout<<ve[i].first<<' '<<ve[i].second<<'\n';
		}
//		cout<<'\n';
		for(int i=0;i<ve.size();i++)
		{
			bool temp=true;
			for(int k=ve[i].first;k<=ve[i].second;k++)
				if(flag[k]==1)
					temp=0;
			if(!temp)	continue;
			ans++;
			for(int k=ve[i].first;k<=ve[i].second;k++)
				flag[k]=1;
		}
		cout<<ans;
	}
	return 0;
}