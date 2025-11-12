#include<bits/stdc++.h>
using namespace std;
int a[1000005][5]; 
int cnt[1000005],d[1000005],cha[1000005];
int g[1000005],tt;
int ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof cnt);
		tt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxx=1;
		for(int j=1;j<=3;j++)
		{
			if(a[i][maxx]<a[i][j]){
				maxx=j;
			}
		}
		d[i]=maxx;
		cnt[maxx]++;
		if(maxx==1)maxx=2;
		else maxx=1;
		for(int j=1;j<=3;j++){
			if(d[i]==j)continue;
			if(a[i][maxx]<a[i][j]){
				maxx=j;
			}
		}
		cha[i]=a[i][d[i]]-a[i][maxx];
		ans+=a[i][d[i]];
	}
	int st=0;
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]*2>n){
			for(int j=1;j<=n;j++)
			{
				if(d[j]==i){
					g[++tt]=cha[j];
				}
			}
			st=i;
			break;
		}
	}
	sort(g+1,g+1+tt);
	for(int i=1;i<=cnt[st]-n/2;i++){
		ans-=g[i];
	}
	cout<<ans<<endl;
	}
}
