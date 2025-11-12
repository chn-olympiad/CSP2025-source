#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+10;
int n,k,a[N],s[N];
bool cmp(pair<int,int>x,pair<int,int> y)
{
	if(x.second==y.second)
	{
		return x.first<y.first;
	}
	return x.second<y.second;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3000)
	{
		for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
		vector<pair<int,int> >b;
		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				if((s[r]^s[l-1])==k)
				{
					b.push_back({l,r});
//					cout<<l<<" "<<r<<"\n";
				}
			}
		}
		
		sort(b.begin(),b.end(),cmp);
		
		queue<int>q;
		q.push(0); 
		int m=1,le=b.size();
		for(int i=1;i<le;i++)
		{
			if(b[i].first>b[0].second)break;
			q.push(i);
			m++; 
		}
		int ans=0;
		while(q.size())
		{
			int u=q.front();
			q.pop();
			int res=1;
			for(int i=m;i<le;i++)
			{
				if(b[u].second<b[i].first)
				{
					u=i;
					res++;
				}
			}
//			cout<<res<<"\n";
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	else
	{
		if(k==1)
		{
			int num=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)num++;
			}
			cout<<num;
			return 0;
		}
		else if(k==0)
		{
			int num=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]=='0')
				{
					num++;
					num+=(sum/2);
				}
				else sum++;
			}
			num+=(sum/2);
			cout<<num;
		}
		else
		{
			int cnt=0,l=1,ans=0;
			for(int i=1;i<=n;i++)
			{
				cnt^=a[i];
				int p=0;
				for(int j=l;j<=i;j++)
				{
					if(p==(k^cnt))
					{
						l=i+1;
						ans++;
						cnt=0;
						break;
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
