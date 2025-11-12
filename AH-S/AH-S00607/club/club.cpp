#include<bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,cnt[5],d[Maxn],ans,a[Maxn][5],tmp[Maxn],tot;
void work(){
	scanf("%d",&n);cnt[1]=cnt[2]=cnt[3]=ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
		if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){d[i]=1;++cnt[1];ans+=a[i][1];}
		else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){d[i]=2;++cnt[2];ans+=a[i][2];}
		else{d[i]=3;++cnt[3];ans+=a[i][3];}
	}
	if (cnt[1]>n/2){
		int m=cnt[1]-n/2;tot=0;
		for(int i=1;i<=n;++i) if (d[i]==1) tmp[++tot]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		sort(tmp+1,tmp+1+tot);
		for(int i=1;i<=m;++i) ans-=tmp[i];
	}
	else if (cnt[2]>n/2){
		int m=cnt[2]-n/2;tot=0;
		for(int i=1;i<=n;++i) if (d[i]==2) tmp[++tot]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		sort(tmp+1,tmp+1+tot);
		for(int i=1;i<=m;++i) ans-=tmp[i];
	}
	else if (cnt[3]>n/2){
		int m=cnt[3]-n/2;tot=0;
		for(int i=1;i<=n;++i) if (d[i]==3) tmp[++tot]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		sort(tmp+1,tmp+1+tot);
		for(int i=1;i<=m;++i) ans-=tmp[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--) work();
	return 0;
}
