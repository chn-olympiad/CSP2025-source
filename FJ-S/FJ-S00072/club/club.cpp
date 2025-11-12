#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[110000][4],b[110000],s[4],x,d[110000],m;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])b[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])b[i]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])b[i]=3;
		}
		s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++)s[b[i]]++;
		ans=0;
		for(int i=1;i<=n;i++)ans+=a[i][b[i]];
		if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=3;i++){
			if(s[i]>n/2)x=i;
		}
		m=0;
		for(int i=1;i<=n;i++){
			if(b[i]==x){
				d[++m]=1000000000;
				if(x!=1)d[m]=min(d[m],a[i][x]-a[i][1]);
				if(x!=2)d[m]=min(d[m],a[i][x]-a[i][2]);
				if(x!=3)d[m]=min(d[m],a[i][x]-a[i][3]);
			}
		}
		sort(d+1,d+m+1);
		for(int i=1;i<=m-n/2;i++)ans-=d[i];
		printf("%lld\n",ans);
	}
	return 0;
}
