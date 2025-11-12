//GZ-S00208 北京师范大学贵阳附属中学 曾敬杰 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ans,cnt;
int T,n;
struct abc{
	int a,b,c;
	int maxn;
}p[N];
bool cmpa(abc x,abc y){
	return x.a > y.a;
}
bool cmpb(abc x,abc y){
	return x.b > y.b;
}
bool cmpc(abc x,abc y){
	return x.c > y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].maxn = max(p[i].a,max(p[i].b,p[i].c));
		}
		sort(p+1,p+1+n,cmpa);
		for(int i = 1;i <= n;i++){
			if(cnt < n/2 && p[i].a == p[i].maxn){
				ans += p[i].a;
				cnt++;
			}else if(cnt == n/2 && p[i].a == p[i].maxn){
				p[i].maxn = max(p[i].b,p[i].c);
			}
		}
		cnt = 0;
		sort(p+1,p+1+n,cmpb);
		for(int i = 1;i <= n;i++){
			if(cnt < n/2 && p[i].b == p[i].maxn){
				ans += p[i].b;
				cnt++;
			}else if(cnt == n/2 && p[i].b == p[i].maxn){
				p[i].maxn = p[i].c;
			}
		}
		cnt = 0;
		sort(p+1,p+1+n,cmpc);
		for(int i = 1;i <= n;i++){
			if(cnt < n/2 && p[i].c == p[i].maxn){
				ans += p[i].c;
				cnt++;
			}
		}
		printf("%d\n",ans);
		ans = 0;	
		cnt = 0;	
	}
	return 0;
}
