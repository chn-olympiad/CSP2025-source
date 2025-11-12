#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
long long ans = 1e9;
int fa[100005];

int vilg_bild[15];
bool vilg_use[15];

struct node{
	int a,b;
	int z;
	long long w;
}Ma_p[10000005];
int temp_in = 0;

bool cmp(node a,node b){
	return a.w < b.w;
}

int find_f(int a){
	if(fa[a] == a){
		return a;
	}
	return fa[a] = find_f(fa[a]);
}

void biltree(){
	for(int i = 1; i <= temp_in - 1; i++){
		fa[i] = i;
	}
	long long out = 0;
		
	for(int i = 1; i <= k; i++){
		if(vilg_use[i]){
			out += vilg_bild[i];
		}
	}
	
	for(int i = 1; i <= temp_in - 1; i++){
		if(Ma_p[i].z != 0 &&  !vilg_use[Ma_p[i].z]){
			continue;
			
		}
		
		int a = min(Ma_p[i].a,Ma_p[i].b),b = max(Ma_p[i].a,Ma_p[i].b);
		
		
		if(find_f(a) == find_f(b)) {
			continue;
		}
		
		fa[a] = find_f(fa[a]);
		fa[find_f(fa[b])] = fa[find_f(fa[a])];
		
		
		out += Ma_p[i].w;
//		cout<<a<<" "<<b<<" "<<out<<'\n';
//		cout<<fa[a] <<" "<<fa[b]<<'\n';
		
		 
	}
	
	for(int i = 1; i <= n; i++){
//		cout<<fa[i]<<" ";
		
		fa[i] = find_f(fa[i]);
		
		if(find_f(fa[i]) != find_f(fa[1])){
			
			out = 1e9 + 7;
		} 
	}
//	cout<<'\n';
	
//	cout<<out<<"\n";
	
	if(out == 1e9+7){
		return ;
	}
	
	
	
	ans = min(ans,out);
	
}

void dfs(int now){
	if(now == k+1){
		
//		for(int i = 1; i <= k ; i++){
//			cout<<vilg_use[i]<<" ";
//		}
//		cout<<'\n';
		
		
		biltree();
		return ;
	}
	
	dfs(now+1);
	vilg_use[now] = 1;
	dfs(now+1);
	vilg_use[now] = 0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k ;
	
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		Ma_p[i].a = u;
		Ma_p[i].b = v;
		Ma_p[i].w = w;
		Ma_p[i].z = 0;
	}
	
	temp_in = m + 1;
	for(int i = 1; i <= k; i++){
		cin>>vilg_bild[i];
		
		for(int j = 1; j <= n; j++){
			int u = m + i,v = j,w;
			
			cin>>w;
			
			Ma_p[temp_in].a = u;
			Ma_p[temp_in].b = v;
			Ma_p[temp_in].w = w;
			Ma_p[temp_in].z = i;
			temp_in ++ ;
		}
		
	}
	
	sort(Ma_p + 1,Ma_p + temp_in,cmp);
	
//	for(int i = 1; i <= temp_in - 1; i++){
//		cout<<i<<":\n";
//		cout<<Ma_p[i].a<<" "<<Ma_p[i].b<<" "<<Ma_p[i].w<<" C: "<<Ma_p[i].z<<'\n'; 
//	}
	
	dfs(1);

//	fa[1] = 2;
//	fa[2] = 2;
//	fa[3] = 2;
//	fa[4] = 5;
//	fa[5] = 3;
//	
//	fa[4] = find_f(fa[4]);
//	cout<<find_f(fa[4]); 
	
	cout<<ans<<'\n';
	
	return 0;
} 
