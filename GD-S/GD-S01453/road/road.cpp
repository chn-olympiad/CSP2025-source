#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxm=1e6+2;
const int maxn=1e5+2;
int n,m,k,sum;
struct node{
	int u,v;
	int w;
}road[maxm];
struct NODE{
	int k;
	int W;
}coun[12];
int cnt[maxm];
bool cmp(node a,node b){
	return a.w>b.w;
}
bool check(){
	int ans=0;
	for (int i=1;i<=m;i++){
		if (cnt[i]==0)
			return false;
		if (cnt[i]%2!=0)
			ans++; 	
	}
	return (ans<=2);
}
int solve1(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
		cnt[road[i].u]++;
		cnt[road[i].v]++;
		sum+=road[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>coun[i].k>>coun[i].W;
	}
	int f[maxn];
	for (int i=1;i<=n;i++){
		cnt[road[i].u]--;
		cnt[road[i].v]--;
		if (!check()){
			cnt[road[i].u]++;
			cnt[road[i].v]++;
			f[i]=f[i-1];
			continue;
		}
		f[i]=f[i-1]+road[i].w;
	}
	return f[n];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<solve1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
