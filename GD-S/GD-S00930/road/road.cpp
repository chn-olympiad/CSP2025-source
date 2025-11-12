#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{int a,b,val;};
vector<node>e[10005];
long long ans[10005];
int cnt[10005];
bool cmp(node x,node y){
	return x.val<y.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[i].push_back({u,v,w});
	}
	sort(e+1,e+m+1,cmp);
	int t=0;
	for(int i=1;i<=m;i++){
		if(cnt[e[i].a]==2||cnt[e[i].b]==2)continue;
		cnt[e[i].a]++;
		cnt[e[i].b]++;
		ans[t]=e[i].val;
		t++;
	}
	sort(ans,ans+t);
	long long akkk=0;
	for(int i=0;i<t-1;i++)akkk+=ans[i];
	cout << akkk;
	fclose(stdin);
	fclose(stdout);
} 
