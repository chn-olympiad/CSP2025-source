#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,chu[22000010],ans;
struct ppp{
	int from,to,w,now;
}p[22010100];
int head[22010110],cnt;
void add(int x,int y,int z)
{
	p[++cnt].from = head[x];
	p[cnt].now = x;
	p[cnt].to = y;
	p[cnt].w = z;
	head[x] = cnt;
	chu[x]++;
	chu[y]++;
}
bool cmp(ppp a,ppp b){
	return a.w > b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k == 0){
		for(int i = 1 ;i <= m ;i++){
			int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z);
		}
		sort(p + 1,p + 1 + cnt,cmp);
		for(int i = 1;i <= cnt ; i++){
			if(chu[p[i].now] >= 2 && chu[p[i].to] >= 2){
				p[i].w = 0;
				chu[p[i].now]--;
				chu[p[i].to]--;
			}
		}
		for(int i = 1 ;i <= cnt ;i ++) ans += p[i].w;
		printf("%lld",ans);
	}
	else{
		for(int i = 1 ;i <= m ;i++){
			int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z);
		}
		int need[20];
		for(int i = 1 ;i <= k ;i++){
			scanf("%lld",&need[i]);
			int y[10100];
			for(int j = 1;j <= n;j++)
				scanf("%lld",&y[i]);
			for(int j = 1; j <= n ; j ++){
				for(int c = j + 1 ;c <= n ;c++){
					add(j, c, y[j] + y[c]);
				}
			}	
		}
		sort(p+1,p+1+cnt,cmp);
		for(int i = 1;i <= cnt ; i++){
			if(chu[p[i].now] >= 2 && chu[p[i].to] >= 2){
				p[i].w = 0;
				chu[p[i].now]--;
				chu[p[i].to]--;
			}
		}
		for(int i = 1 ;i <= cnt ;i ++) ans += p[i].w;
		printf("%lld",ans);
	}
	
}
