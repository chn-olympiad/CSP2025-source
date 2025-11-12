#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],f[N];
vector<pair<int,int>>v;
bool cmp(pair<int,int>x,pair<int,int>y)
{
	if(x.second==y.second)
		return x.first<y.first;
	return x.second<y.second;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<3e4)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i]=f[i-1]^a[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((f[j]^f[i-1])==k)
					v.push_back({i,j});
		int ans=0,len=v.size(),le=0;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<len;i++)
		{
			if(v[i].first>le)
			{
				ans++;
				le=v[i].second;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
				cnt=0;
				continue;
			}
			cnt=cnt^a[i];
			if(cnt==k)
			{
				ans++;
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
