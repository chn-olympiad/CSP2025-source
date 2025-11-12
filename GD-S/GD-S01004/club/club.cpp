#include<bits/stdc++.h>
using namespace std;
long long a[100005][4],ans,c[100005];
int t[100005],s[100005],cnt[4],n,m,len,k,cnn[4];
int q[4][100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		len=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;++i)
		{
			s[i]=1;t[i]=0;
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][s[i]]<a[i][2])t[i]=s[i],s[i]=2;
			if(a[i][s[i]]<a[i][3])t[i]=s[i],s[i]=3;
			if(t[i]==0)
			{
				if(a[i][2]>a[i][3])t[i]=2;
				else t[i]=3;
			}
			cnt[s[i]]++;
			ans+=a[i][s[i]];
			q[s[i]][++cnn[s[i]]]=i;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)cout<<ans<<endl;
		else
		{
			k=1;
			if(cnt[1]<cnt[2])k=2;
			if(cnt[1]<cnt[3])k=3;
			for(int i=1;i<=cnn[k];++i)
			{
				c[++len]=a[i][s[q[k][i]]]-a[i][t[q[k][i]]];
			}
			sort(c+1,c+1+len);
			for(int i=1;i<=cnt[k]-(n/2);++i)
			{
				ans-=c[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
