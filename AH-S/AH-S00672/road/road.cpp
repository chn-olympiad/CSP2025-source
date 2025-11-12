#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,m;
long long ans;
struct road{
	int u,v,w;
}a[1000115];
int city[1000115];
struct village{
	int c,a[10003];
}b[12];
bool cmp(road a,road b){
	return a.w>b.w;
}
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		city[a[i].u]++;
		city[a[i].v]++;
		ans+=a[i].w;
	}
	int tung=0;
	for(int i=1;i<=k;++i){
		scanf("%d",&b[i].c);
		for(int j=1;j<=n;++j){
			scanf("%d",&b[i].a[j]);
			if(b[i].a[j]==0) {city[n+i]++,city[j]++;a[m+(++tung)].v=j;a[m+tung].u=n+i;a[m+tung].w=0;}
		}
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		int i=1;
		while(m>=n){
			if(city[a[i].u]>1&&city[a[i].v]>1){
				ans-=a[i].w;
				city[a[i].u]--;city[a[i].v]--;
				--m;
			}
			++i;
		}
		printf("%lld",ans);
	}
	else{
		sort(a+1,a+m+tung+1,cmp);
		int i=1;
		while(m+tung>=n+k){
			if(city[a[i].u]>1&&city[a[i].v]>1){
				ans-=a[i].w;
				city[a[i].u]--;city[a[i].v]--;
				--m;
			}
			++i;
		}
		printf("%lld",ans);
	}
	return 0;
}