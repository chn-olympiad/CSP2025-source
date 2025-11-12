#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int T,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		priority_queue<pii,vector<pii>,greater<pii>> q;
		int a=0,b=0,c=0,ans=0;
		for(int i=1; i<=n; i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(max({x,y,z})==x)a++,ans+=x,q.emplace(x-max(y,z),1);
			else if(max({x,y,z})==y)b++,ans+=y,q.emplace(y-max(x,z),2);
			else c++,ans+=z,q.emplace(z-max(x,y),3);
		}
		if(a<=n/2&&b<=n/2&&c<=n/2)
		{
			cout<<ans<<'\n';
			continue;
		}
		int t,cnt;
		if(a>n/2)t=1,cnt=a-n/2;
		else if(b>n/2)t=2,cnt=b-n/2;
		else t=3,cnt=c-n/2;
		while(cnt)
		{
			pii u=q.top();
			q.pop();
			if(u.second==t)ans-=u.first,cnt--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
