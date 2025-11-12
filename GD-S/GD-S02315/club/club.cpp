#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,f[N][3],g[N][3],a[N][3],perdo[N],sangi[N],cnt[3];
vector<int>v;
bool cmp(int x,int y)
{
	return x>y;
}
void init()
{
	cnt[0]=cnt[1]=cnt[2]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		//cout<<t<<endl;
		cin>>n;	
		init();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2])
			{
				cnt[0]++;
				sangi[i]=0;
				perdo[i]=max(a[i][1]-a[i][0],a[i][2]-a[i][0]);
				ans+=a[i][0];
			}
			else if(a[i][1]>a[i][0] and a[i][1]>=a[i][2])
			{
				cnt[1]++;
				sangi[i]=1;
				perdo[i]=max(a[i][0]-a[i][1],a[i][2]-a[i][1]);
				ans+=a[i][1];
			}
			else
			{
				cnt[2]++;
				sangi[i]=2;
				perdo[i]=max(a[i][0]-a[i][2],a[i][1]-a[i][2]);
				ans+=a[i][2];
			}
		}
		int maxnum=max(cnt[0],max(cnt[1],cnt[2]));
		if(maxnum<=n/2)
		{
			cout<<ans<<'\n';
			continue;
		}
		else
		{
			int maxid;
			if(cnt[0]>cnt[1] and cnt[0]>cnt[2])maxid=0;
			else if(cnt[1]>cnt[0] and cnt[1]>cnt[2])maxid=1;
			else maxid=2;
			v.clear();
			for(int i=1;i<=n;i++)
				if(sangi[i]==maxid)v.push_back(perdo[i]);
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<maxnum-n/2;i++)ans+=v[i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
