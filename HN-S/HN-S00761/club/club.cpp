#include <bits/stdc++.h>
using namespace std;
int vis[1000001];
struct st{
	int u,v,w,id;
}a[1000001],b[1000001];
int ans = 0;
bool cmp1(st x,st y){
	if(x.u != y.u)
	return x.u > y.u;
	return max(x.v,x.w) > max(y.v,y.w);
}
bool cmp2(st x,st y){
	if(x.v != y.v)
	return x.v > y.v;
	return max(x.u,x.w) > max(y.u,y.w);
}
bool cmp3(st x,st y){
	if(x.w != y.w)
	return x.w > y.w;
	return max(x.v,x.u) > max(y.v,y.u);
}
int n;
void dfs(int u,int sum,int f1,int f2,int f3){
	if(f1 > n / 2)return;
	if(f2 > n / 2)return;
	if(f3 > n / 2)return;
	if(u == n){
		ans = max(ans,sum);
		return;
	}
	for(int i = u + 1;i <= n;i++){
		if(vis[i])continue;
		vis[i] = 1;
		dfs(i,sum + a[i].u,f1 + 1,f2,f3);
		dfs(i,sum + a[i].v,f1,f2 + 1,f3);
		dfs(i,sum + a[i].w,f1,f2,f3 + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		
		cin >> n;
		int d = n / 2;
		int f1 = 1,f2 = 1;
		for(int i = 1;i <= n;i++){
			cin >> a[i].u>> a[i].v>>a[i].w;
			a[i].id = i;
			if(a[i].v != 0)f1 = 0;
			if(a[i].w != 0)f2 = 0;
			b[i] = a[i];
		}
		
		int sum = 0;
		if(n <= 10){
			dfs(0,0,0,0,0);
			cout << ans<<'\n';
		}else if(f1 && f2){
			sort(a + 1,a + n + 1,cmp1);
			for(int i = 1;i <= n / 2;i++){
				ans += a[i].u;
			}
			cout<< ans<<'\n';
		}else if(f1){
			sort(a + 1,a + n + 1,cmp1);
			sort(b + 1,b + n + 1,cmp2);
			int sum = 0;
			for(int i = 1,j = 1;i <= n || j <= n;){
				if(vis[a[i].id]){
					if(!vis[b[j].id]){
						sum += b[j].v;
					}else{
						if(j != n)
						j++;
					}
					if(i != n)
					i++;
				}else if(vis[b[j].id]){
					if(!vis[a[i].id]){
						sum += a[i].u;
					}else{
						if(i != n)
						i++;
					}
					if(j != n)
					j++;
				}else{
					i++,j++;
				}
			}
			cout << sum<<'\n';
		}else{
			sort(a + 1,a + n + 1,cmp3);
			int sum = 0;
			for(int i = 1;i <= n / 2;i++){
				sum += a[i].w;
			}
			for(int i = n / 2 + 1;i <= n;i++){
				sum += max(a[i].u,a[i].v);
			}
			cout << sum<<'\n';
		}
		ans = 0;
		memset(vis,0,sizeof vis);
	}
	return 0;
}
