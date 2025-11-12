#include <bits/stdc++.h>
using namespace std;
struct side{
	int u,v,w;
};
vector<side> s;
side s1[1100000];
int n,m,k,a,c[11],fa[10015],sum;
bool vis[10015];
int find(int v){
	return fa[v] == v ? v : fa[v] = find(fa[v]); 
}
bool cmp(side x,side y){
	return x.w < y.w;
}
int main(){
	//输入城市 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	for (int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		s.push_back((side){u,v,w});
		//s.push_back((side){v,u,w});
	}
	//输入乡村 
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int i = 1;i <= n;i++){
			cin >> a;
			s.push_back((side){n + k,i,a});
			//s.push_back((side){i,n + k,a});
		}
	}
	//最小生成树 
	for (int i = 1;i <= n + k;i++) fa[i] = i;
	for (int i = 0;i < m + n * k;i++) s1[i] = s[i];
	sort(s1,s1 + m + n * k,cmp);
	//for (int i = 0;i < m + n * k;i++) cout << s1[i].u << " " << s1[i].v << " " << s1[i].w << endl;
	//for (int i = 0;i < s.size();i++) cout << s[i].u << " " << s[i].v << " " << s[i].w << endl;
	for (int i = 0;i < m + k * n;i++){
		if (find(s1[i].u) != find(s1[i].v)){
			fa[s1[i].u] = find(s1[i].v);
			//cout << find(s1[i].u) << find(s1[i].v) << " ";
			sum += s1[i].w;
		}
	}
	cout << sum;
	return 0;
}
