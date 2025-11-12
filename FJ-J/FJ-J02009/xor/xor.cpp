#include<bits/stdc++.h>
using namespace std;
struct qujian
{
	int l,r;
};
int n,k,a[500020];
vector<qujian>b;
int yh(int x,int y)
{
	int ans=0,cnt=0;
	while(x!=0 or y!=0)
	{
		if(x%2!=y%2)
			ans+=pow(2,cnt);
		x/=2;
		y/=2;
		cnt++;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		if(x==k)
			b.push_back({i,i});
		for(int j=i+1;j<n;j++)
		{
			x=yh(x,a[j]);
			if(x==k)
				b.push_back({i,j});	
		}
	}
	int x=b[0].r,ans=1;
	for(int i=1;i<b.size();i++)
	{
		if(x<b[i].l)
		{
			x=b[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
