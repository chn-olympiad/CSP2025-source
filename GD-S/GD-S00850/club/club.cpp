#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,w[10005],cnt[5];
pair<int,int>a[100005][5];
int pow3(int x)
{
	int res=1;
	for(int i=1;i<=x;i++)res*=3;
	return res;
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			w[i]=1;
			for(int j=1;j<=3;j++)cin>>a[i][j].first,a[i][j].second=j;
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=pow3(n);i++)
		{
			bool ok=1;
			int q=1;
			while(w[q]>3)w[q]=1,w[q+1]++,q++;
			cnt[1]=0,cnt[2]=0,cnt[3]=0;
			for(int j=1;j<=n;j++)cnt[a[j][w[j]].second]++;
			for(int i=1;i<=3;i++)
			{
				if(cnt[i]>n/2)
				{
					ok=0;
					break;
				}
			}
			if(ok==1)
			{
				int sum;
				for(int i=1;i<=n;i++)
				{
					sum+=a[i][w[i]].first;
				}
				cout<<sum<<endl;
				break;
			}
			w[1]++;
		}
	}
}
