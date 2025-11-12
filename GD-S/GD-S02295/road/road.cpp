#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct road{
	int u, v, w;
}a[1000010];
int b[10010];
int ck(int n){
	if(b[n]!=n)b[n]=ck(b[n]);
	return b[n];
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<m;i++)scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	sort(a, a+m, [](road n1, road n2){
		return n1.w<n2.w;
	});
	for(int i=0;i<n;i++)b[i]=i;
	int t=0;
	long long sum=0;
	vector<int>ve;
	for(int i=0;i<m;i++){
		if(ck(a[i].u)!=ck(a[i].v)){
			b[a[i].u]=a[i].v;
			ve.push_back(i);
			t++;
			sum+=a[i].w;
		}
		if(t==n-1)break;
	}
	if(!k){
		printf("%lld", sum);
		return 0;
	}
	for(int i=0;i<k;i++){
		bool ok=1;
		int cnp;
		for(int i=0;i<=n;i++){
			scanf("%d", &cnp);
			if(cnp)ok=0;
		}
		if(ok){
			printf("0");
			return 0;
		}
	}
	printf("%lld", sum);
	return 0;
}
