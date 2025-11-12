#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
typedef pair<ll,ll> pii;
struct node{
	int u,v,w;
	bool operator<(const node &t){
		return w < t.w;
	}
}e[1050050];
int num;
ll ans;
int n,m,k; 
int c[N];
int f[N];
int find(int x){
	if(x != f[x])return f[x] = find(f[x]);
	return x;
}
void kru(){
	for(int i = 1;i <= n; i++)f[i] = i;
	int cnt = 0;
	for(int i = 1;i <= num; i++){
		node t = e[i];
//		cout<<t.w<<"\n";
		if(find(t.u) != find(t.v)){
			ans += t.w;
			f[find(t.v)] = f[find(t.u)];
			cnt++;	
		}
		if(cnt == n - 1)break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1,u,v,w;i <= m; i++){
		scanf("%d%d%d",&u,&v,&w);
		e[++num] = (node){u,v,w};
		e[++num] = (node){v,u,w};
	}
	for(int i = 1;i <= k; i++){
		scanf("%d",&c[1]);
		for(int j = 1;j<=n;j++){
			scanf("%d",&c[j]);
		}
		for(int j = 1;j<=n;j++){
		{
			if(c[j]==0){
				
				for(int l =1;l<=n;l++)
					if(l!=j)
					{
						e[++num]=(node){j,l,c[l]};
						e[++num]=(node){l,j,c[l]};
					}
			}
		}
	}
	}
	sort(e+1,e+num+1);
	kru();
	cout<<ans<<"\n";
	return 0;
}  
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 9 9 9 0
*/
