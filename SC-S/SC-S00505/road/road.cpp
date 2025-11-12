#include <bits/stdc++.h>
using namespace std;
long long n,m,k,sum,c,a[1000006];
bool b[100005] = {false};
vector<long long> edgeu;
vector<long long> edgev;
vector<long long> sdge; 
bool dis[1000005] = {true};
struct Rcioad
{
	long long u,v,w;
} d[1000005];
bool cmp(Rcioad x,Rcioad y)
{
	return x.w < y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for (int i = 1;i <= m;i++) {
		scanf("%lld %lld %lld",&d[i].u,&d[i].v,&d[i].w);
		edgeu.push_back(d[i].v);
		edgev.push_back(d[i].u);
		sdge.push_back(d[i].w);
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= m;j++){
			if (d[i].u == d[j].u && d[i].v == d[j].v){
				if (d[i].w <= d[j].w) dis[j] = false;
			}
		}
	}
	for (int l = 1;l <= k;l++){
		scanf("%lld",&c);
		for (int j = 1;j <= n;j++) {
			scanf("%lld",&a[j]);
			edgeu.push_back(j);
			edgev.push_back(-1);
			sdge.push_back(a[j] + c);
		}
	}
	sort(d + 1,d + n + 1,cmp);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= k;i++)
	{
		for (int j = 1;j <= n;j++){
			if (a[i] == a[j]) {
				b[i] = true;
				sum += sdge[m + i - 1];
			}
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= k;j++){
			if (d[i].w <= a[j]) {
				sum += sdge[i-1] - sdge[m + i - 1];
				for (int l = 1;l <= k;i++){
					if(edgeu[i - 1] == l) sum -= sdge[m + l - 1];
				}
			}
		}
	}
	printf("%lld",sum);
	return 0;
}