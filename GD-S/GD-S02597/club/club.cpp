#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int x,y,z;
}a[100100];
int c[3],f[100100],ans,n;

void dfs(int step,int s){
	if(step > n){
		ans = max(ans,s);
		return;
	}
	if(c[0] < n/2){
		c[0]++;
		dfs(step+1,s+a[step].x);
		c[0]--;
	}
	if(c[1] < n/2){
		c[1]++;
		dfs(step+1,s+a[step].y);
		c[1]--;
	}
	if(c[2] < n/2){
		c[2]++;
		dfs(step+1,s+a[step].z);
		c[2]--;
	}
}

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	for(cin>>T; T--; cout<<'\n'){
		cin>>n;
		ans = c[0] = c[1] = c[2] = 0;
		for(int i = 1; i <= n; i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			f[i] = 0;
		}
		if(n > 20){
			sort(a+1,a+n+1,[](Node a,Node b){
				return a.x > b.x;
			});
			for(int i = 1; i <= n/2; i++){
				ans += a[i].x;
				f[i] = 1;
			}
			for(int i = 1; i <= n; i++){
				ans += a[i].y*(1-f[i]);
				f[i] = 1;
			}
			for(int i = 1; i <= n; i++){
				ans += a[i].z*(1-f[i]);
				f[i] = 1;
			}
			cout<<ans;
			continue;
		}
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}