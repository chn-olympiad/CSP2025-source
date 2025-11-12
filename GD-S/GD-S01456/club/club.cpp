#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
int t,n,a[N][3],c[N],cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt[0]=cnt[1]=cnt[2]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=mx;
			if(a[i][0]==mx)
			{
				cnt[0]++;
				c[i]=0;
			}
			else if(a[i][1]==mx)
			{
				cnt[1]++;
				c[i]=1;
			}
			else
			{
				cnt[2]++;
				c[i]=2;
			}
		}
		for(int x=0;x<=2;x++)
		if(cnt[x]>n/2)
		{
			vector<int> tmp;
			for(int i=1;i<=n;i++)
			if(c[i]==x)
			{
				int val=0;
				for(int j=0;j<=2;j++)
				if(j!=x)
				 val=max(val,a[i][j]);
				tmp.push_back(a[i][x]-val);
			}
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<cnt[x]-n/2;i++)
			 ans-=tmp[i];
			break;
		}
		cout<<ans<<"\n";
	}
}
