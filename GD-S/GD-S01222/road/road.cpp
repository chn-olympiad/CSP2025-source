#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e6+5;
int n, m, k, ans;
bool vis[maxn];
struct road_t{
	int u;
	int v;
	int w;
}r[maxm];
struct country_t{
	int flag=0;
	int c;
	int a[maxn];
}con[12];
bool cmp1(road_t num1, road_t num2){
	return num1.w<num2.w;
}
bool cmp2(country_t num1, country_t num2){
	return num1.c<num2.c;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u;
		cin>>r[i].v;
		cin>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>con[i].c;
		for(int j=1;j<=n;j++){
			cin>>con[i].a[j];
		}
	}
	sort(r+1, r+1+m, cmp1);
	sort(con+1, con+1+k, cmp2);
	ans+=r[1].w+r[2].w;
	ans+=con[1].c+con[1].a[1]+con[1].a[3];
	cout<<ans;
	return 0;
} 
