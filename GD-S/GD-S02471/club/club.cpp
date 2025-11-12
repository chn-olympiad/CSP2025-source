#include<bits/stdc++.h>
#define N 100007

using namespace std;

int n,a[N][4],b[N];

void mian(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	int ans=0,c[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		int mx=max({a[i][1],a[i][2],a[i][3]});
		ans+=mx;
		for(int j:{1,2,3}) if(mx==a[i][j]) {c[j]++,b[i]=j;break;}
	}
	for(int i:{1,2,3}) if(c[i]>n/2){
		vector<int> s;
		for(int j=1;j<=n;j++) if(b[j]==i){
			int d=-1e9;
			for(int k:{1,2,3}) if(i!=k) d=max(d,a[j][k]);
			d=a[j][i]-d;
			s.push_back(d);
		}
		sort(s.begin(),s.end());
		for(int j=1;j<=c[i]-n/2;j++) ans-=s[j-1];
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) mian();
	return 0;
}
