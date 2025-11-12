#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long n,a[N][3],ans,cnt[3],minn[3][N];
void solve()
{
	ans=0,cnt[0]=cnt[1]=cnt[2]=0;
	memset(minn,0,sizeof(minn));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	for(int i=1;i<=n;i++)
	{
		long long fir=0,sec=0,firp=0;
		for(int j=0;j<3;j++)
		{
			if(a[i][j]>fir) sec=fir,fir=a[i][j],firp=j;
			else if(a[i][j]>sec) sec=a[i][j];
		}
		cnt[firp]++;
		minn[firp][cnt[firp]]=fir-sec;
		ans+=fir;
	}
//	cerr<<'*';
	for(int i=0;i<3;i++) if(cnt[i]>n/2)
	{
		int m=cnt[i]-n/2;
		sort(minn[i]+1,minn[i]+cnt[i]+1);
		for(int j=1;j<=m;j++) ans-=minn[i][j];
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
