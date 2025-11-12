#include<iostream>
#include<algorithm>
using namespace std;
struct node{int id,x;};
int n,ans,p[100005][5],cs[100005],cnt[5];
bool cmp(node x,node y){return x.x<y.x;
}
int mainn(){
	cnt[1]=cnt[2]=cnt[3]=0;
	scanf("%d",&n);ans=0;
	for(int i=1;i<=n;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		int maxx=max(max(a,b),c);ans+=maxx;
		if(maxx==a)cnt[1]++,cs[i]=1;
		else if(maxx==b)cnt[2]++,cs[i]=2;
		else cnt[3]++,cs[i]=3;
		p[i][1]=a;p[i][2]=b;p[i][3]=c;
	}
	while(1){
		if(max(max(cnt[1],cnt[2]),cnt[3])<=(n>>1)){
			printf("%lld\n",ans);
			break;
		}int u=1;
		while(cnt[u]<=(n>>1))u++;
		node a[100005];int cntt=0;
		for(int i=1;i<=n;i++){
			if(cs[i]^u)continue;
			int maxx=0;
			for(int j=1;j<=3;j++)if(j^u&&p[i][j]<=p[i][u]&&p[i][j]>p[i][maxx])maxx=j;
			a[++cntt]=node{maxx,p[i][u]-p[i][maxx]};
		}
		sort(a+1,a+1+cntt,cmp);
		for(int i=1;cnt[u]>(n>>1);i++){
			ans-=a[i].x;
			cnt[u]--;cnt[a[i].id]++;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)mainn();
	return 0;
}
