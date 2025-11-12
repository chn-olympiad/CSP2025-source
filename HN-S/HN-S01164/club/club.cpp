#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],d[N][2],sum[4],v[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	for(;T--;)
	{
		memset(sum,0,sizeof sum);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]) sum[1]++;
			else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]) sum[2]++;
			else sum[3]++;
		}
		int base;
		if(max(sum[1],max(sum[2],sum[3]))==sum[1]) base=1;
		else if(max(sum[1],max(sum[2],sum[3]))==sum[2]) base=2;
		else base=3;
		if(base==1)for(int i=1;i<=n;i++) d[i][0]=a[i][2]-a[i][1],d[i][1]=a[i][3]-a[i][1];
		else if(base==2)for(int i=1;i<=n;i++) d[i][0]=a[i][1]-a[i][2],d[i][1]=a[i][3]-a[i][2];
		else for(int i=1;i<=n;i++) d[i][0]=a[i][1]-a[i][3],d[i][1]=a[i][2]-a[i][3];
		for(int i=1;i<=n;i++) v[i]=max(d[i][0],d[i][1]);
		sort(v+1,v+1+n);
		reverse(v+1,v+1+n);
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][base];
//		cout<<ans<<' ';
		for(int i=1;i<=n;i++)
		{
			if(v[i]<0&&i>n>>1) break;
			ans+=v[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
