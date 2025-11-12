#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
const int N=1e5+5;
int a[N],b[N],c[N];
int s1[N],s2[N],s3[N];
int cnt[4];
int sum,minn,maxn,mid;
int Sum;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		Sum=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			sum=a[i]+b[i]+c[i];
			minn=min(a[i],min(b[i],c[i]));
			maxn=max(a[i],max(b[i],c[i]));
			mid=sum-maxn-minn;
			if(maxn==a[i])
				s1[++cnt[1]]=maxn-mid;
			else if(maxn==b[i])
				s2[++cnt[2]]=maxn-mid;
			else s3[++cnt[3]]=maxn-mid;
			Sum+=maxn;
		}
		if(cnt[1]>n/2)
		{
			sort(s1+1,s1+cnt[1]+1);
			for(int i=1;i<=cnt[1]-n/2;i++)
				Sum-=s1[i];
		}
		else if(cnt[2]>n/2)
		{
			sort(s2+1,s2+cnt[2]+1);
			for(int i=1;i<=cnt[2]-n/2;i++)
				Sum-=s2[i];
		}
		else if(cnt[3]>n/2)
		{
			sort(s3+1,s3+cnt[3]+1);
			for(int i=1;i<=cnt[3]-n/2;i++)
				Sum-=s3[i];
		}
		cout<<Sum<<'\n';
	}
	return 0;
}

