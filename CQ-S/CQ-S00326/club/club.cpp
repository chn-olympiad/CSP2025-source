#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int L;
L n,cnt[5],sum,t;
struct s{
	L c[5],ch,b;
};
s a[150005];
bool f(s p,s q){return p.b < q.b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		sum = 0LL;
		cnt[1] = 0LL;
		cnt[2] = 0LL;
		cnt[3] = 0LL;
		for(L i = 1LL;i <= n;i++){
			scanf("%lld %lld %lld",&a[i].c[1],&a[i].c[2],&a[i].c[3]);
			if(a[i].c[1] >= a[i].c[2] && a[i].c[1] >= a[i].c[3]){
				sum += a[i].c[1],cnt[1]++,a[i].b = ((a[i].c[2] > a[i].c[3])?(a[i].c[1] - a[i].c[2]):(a[i].c[1] - a[i].c[3]));
				a[i].ch = 1LL;
			}
			else if(a[i].c[1] <= a[i].c[2] && a[i].c[2] >= a[i].c[3]){
				sum += a[i].c[2],cnt[2]++,a[i].b = ((a[i].c[1] > a[i].c[3])?(a[i].c[2] - a[i].c[1]):(a[i].c[2] - a[i].c[3]));
				a[i].ch = 2LL;
			}
			else{
				sum += a[i].c[3],cnt[3]++,a[i].b = ((a[i].c[1] > a[i].c[2])?(a[i].c[3] - a[i].c[1]):(a[i].c[3] - a[i].c[2]));
				a[i].ch = 3LL;
			}
		}
		sort(a + 1LL,a + n + 1LL,f);
		if(cnt[1] > (n >> 1LL)){
			for(L i = 1LL;i <= n;i++){
				if(a[i].ch == 1LL){
					cnt[1]--;
					sum -= a[i].b;
					if(cnt[1] <= (n >> 1LL)){break;}
				}
			}
		}
		else if(cnt[2] > (n >> 1LL)){
			for(L i = 1LL;i <= n;i++){
				if(a[i].ch == 2LL){
					cnt[2]--;
					sum -= a[i].b;
					if(cnt[2] <= (n >> 1LL)){break;}
				}
			}
		}
		else if(cnt[3] > (n >> 1LL)){
			for(L i = 1LL;i <= n;i++){
				if(a[i].ch == 3LL){
					cnt[3]--;
					sum -= a[i].b;
					if(cnt[3] <= (n >> 1LL)){break;}
				}
			}
		}
		printf("%lld",sum);
		putchar('\n');
	}
	return 0;
}
