#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
	long long delta;
	int add,type;
	bool operator <(const node &x) const{ return delta < x.delta; }
};
node a[N];
int T;
int n,v[N][4],p,q,r,ans,cnt[4];
void init(){
	memset(v,0,sizeof(v));
	for(int i = 1; i <= n; i++) a[i].add = 0,a[i].delta = 0,a[i].type = 0;
	ans = 0,cnt[1] = 0,cnt[2] = 0,cnt[3] = 0;
}
void work(){
	scanf("%d",&n);
	init();
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d",&p,&q,&r);
		v[i][1] = p,v[i][2] = q,v[i][3] = r;
		if(p >= max(q,r)) v[i][0] = 1;
		else if(q >= max(p,r)) v[i][0] = 2;
		else if(r >= max(p,q)) v[i][0] = 3;
		r = min(p,min(q,r));
		p = v[i][v[i][0]];
		q = v[i][1] + v[i][2] + v[i][3] - p - r;
		a[i].add = i,a[i].delta = p - q,a[i].type = v[i][0];
		ans += p,cnt[v[i][0]]++;
	}
	sort(a + 1,a + n + 1);
	if(cnt[1] > (n >> 1)){
		for(int i = 1; i <= n; i++){
			if(a[i].type != 1) continue;
			ans -= a[i].delta,--cnt[1];
			if(cnt[1] == (n >> 1)) break;
		}
	}else if(cnt[2] > (n >> 1)){
		for(int i = 1; i <= n; i++){
			if(a[i].type != 2) continue;
			ans -= a[i].delta,--cnt[2];
			if(cnt[2] == (n >> 1)) break;
		}
	}else if(cnt[3] > (n >> 1)){
		for(int i = 1; i <= n; i++){
			if(a[i].type != 3) continue;
			ans -= a[i].delta,--cnt[3];
			if(cnt[3] == (n >> 1)) break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
