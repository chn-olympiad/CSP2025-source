#include<bits/stdc++.h>
using namespace std;
const int kmaxN = 1e5+10;
int T,n;
struct bu{
	int o,t,h;
}a[kmaxN];
bool fa =1,fb = 1;
long long ans =0;
bool cmp(bu x,bu y){
	if(x.o != y.o) return x.o > y.o;
	else{
		if(x.t != y.t) return x.t>y.t;
		else return x.h>y.h;
	} 
}
int xu[5];
void dfs(int x,long long sum){
	ans = max(ans,sum);
	if(x > n){		
		return;
	}
	for(int i = 1;i <= n;i++){
		if(xu[i] < n/2){
			xu[i]++;
			if(i == 1 && a[x].o ){
				ans = max(ans,sum+a[x].o);
				dfs(x+1,sum+a[x].o);
			}
			else if(i == 2 && a[x].t){
				ans = max(ans,sum+a[x].t);
				dfs(x+1,sum+a[x].t);
			} 
			else{
				if(i == 3 && a[x].h)
				dfs(x+1,sum+a[x].h);
			} 
			xu[i]--;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].o>>a[i].t>>a[i].h;
			if(a[i].t || a[i].h) fa = 0;
		}
		
		sort(a+1,a+n+1,cmp);
		if(fa){
			for(int i = 1;i <= n/2;i++){
				ans+=a[i].o;
			}
			cout<<ans<<'\n';
			continue;
		}
		memset(xu,0,sizeof(xu)); 
		dfs(1,0); 
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0

*/
