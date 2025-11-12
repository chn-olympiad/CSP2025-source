#include<bits/stdc++.h>
using namespace std;
const int dd=5e5+5;
int a[dd],s[1005][1005];
struct sum
{
	int l;
	int r;
};
vector<sum> m;
bool cmp(sum l,sum r)
{
	return l.r<r.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool ia=1,ib=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) ia=0;
		if(a[i]>1) ib=0;
	}
	if(ia)
	{
		cout<<n/2;
		return 0;
	}
	if(ib)
	{
		int n0=0,n11=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) n0++;
		};
		for(int i=1;i<n;i++)
		{
			if(a[i]==1&&a[i+1]==1) n11++,i++;
		}
		if(k==0) cout<<n0+n11;
		else cout<<n-n0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s[i][i]=a[i];
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			s[i][j]=s[i][j-1]^a[j];
		}
	}	
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			if(s[i][j]==k)
			{
				m.push_back(sum{i,j});
			}
		}
	}
	sort(m.begin(),m.end(),cmp);
	int t=0,ans=0;
	for(int i=0;i<(int)m.size();i++)
	{
		if(m[i].l>t)
		{
			t=m[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
