#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,a[4][100005],cnt[4],s[100005],i,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	for(;t;t--)
	{
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=m=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>=max(a[2][i],a[3][i]))
			{
				ans+=a[1][i];
				cnt[1]++;
			}
			else if(a[2][i]>=max(a[1][i],a[3][i]))
			{
				ans+=a[2][i];
				cnt[2]++;
			}
			else
			{
				ans+=a[3][i];
				cnt[3]++;
			}
		}
		if(cnt[1]>(n>>1))
		{
			for(i=1;i<=n;i++) if(a[1][i]>=max(a[2][i],a[3][i])) s[++m]=a[1][i]-max(a[2][i],a[3][i]);
			sort(s+1,s+m+1);
			for(i=1;i<=cnt[1]-(n>>1);i++) ans-=s[i];
		}
		if(cnt[2]>(n>>1))
		{
			for(i=1;i<=n;i++) if(a[2][i]>=max(a[1][i],a[3][i])) s[++m]=a[2][i]-max(a[1][i],a[3][i]);
			sort(s+1,s+m+1);
			for(i=1;i<=cnt[2]-(n>>1);i++) ans-=s[i];
		}
		if(cnt[3]>(n>>1))
		{
			for(i=1;i<=n;i++) if(a[3][i]>=max(a[1][i],a[2][i])) s[++m]=a[3][i]-max(a[1][i],a[2][i]);
			sort(s+1,s+m+1);
			for(i=1;i<=cnt[3]-(n>>1);i++) ans-=s[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
