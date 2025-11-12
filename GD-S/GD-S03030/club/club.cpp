#include<bits/stdc++.h>
using namespace std;
bool use[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		pair<int,int>a[10010],b[10010],c[10010];
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].first>>b[i].first>>c[i].first;
		sort(b+1,b+n+1);
		if(b[n].first==0)
		{
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--)
			ans+=a[i].first;
			cout<<ans<<endl;
		}
		else
		{
			sort(c+1,c+n+1);
			if(c[n].first==0)
			{
				sort(a+1,a+n+1);
				sort(b+1,b+n+1);
				int suma=0,sumb=0,used[100010];
				memset(used,0,sizeof(used));
				for(int i=n;i>=1;i--)
				{
					if(a[i].second==b[i].second&&!used[a[i].second])
					{
						if(a[i].first>b[i].first&&suma<=n/2)
						{
							suma++;
							ans+=a[i].first;
							used[a[i].second]=1;
						}
						else if(a[i].first<b[i].first&&sumb<=n/2)
						{
							sumb++;
							ans+=b[i].first;
							used[a[i].second]=1;
						}
						else
						{
							if(suma<sumb) suma++,ans+=a[i].first;
							else sumb++,ans+=b[i].first;
							used[a[i].second]=1;
						}
					}
					else
					{
						if(!used[a[i].second]&&suma<=n/2)
						{
							suma++;
							used[a[i].second]=1;
							ans+=a[i].first;
						}
						if(!used[b[i].second]&&sumb<=n/2)
						{
							sumb++;
							used[b[i].second]=1;
							ans+=b[i].first;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*

*/
