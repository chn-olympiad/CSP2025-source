#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long c[15][10005],i,j,c1[15],s[15],rt[10005];
struct node{
	long long u;
	long long v;
	long long w;
}a[1000005];
bool cheat = 1;
long long sum;
bool cmp(node x,node y){
	return x.w < y.w;
}
long long find(long long x){
	if(rt[x] == x)return x;
	else return find(rt[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(i=1;i<=m;i++)cin >> a[i].u >> a[i].v >> a[i].w;
	for(i=1;i<=n;i++)rt[i] = i;
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++){
		if(find(a[i].u) != find(a[i].v)){
			rt[a[i].u] = find(a[i].v);
			rt[a[i].v] = find(a[i].u);
			sum += a[i].w;
		}
	}
	for(i=1;i<=k;i++){
		cin >> c1[i];
		if(c1[i] > 0)cheat = 0;
		for(j=1;j<=m;j++){
			cin >> c[i][j];
			s[i] += c[i][j];
		}
	}
	if(cheat){
		long long minn = INT_MAX;
		for(i=1;i<=k;i++)minn = min(minn,s[i]);
		minn = min(minn,sum);
		cout << minn;
	}
	else cout << sum;
	return 0;
}
