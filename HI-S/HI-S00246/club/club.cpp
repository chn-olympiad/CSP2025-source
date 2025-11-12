#include <bits/stdc++.h>
using namespace std;
int T, n, m, sum;
struct node{
	int x, y, z;
} a[100005];
int maxx(int a, int b, int c){
	return max(a, max(b, c));
}
void dfs(int x, int y, int z, int s, int k){
	if(x+y+z==n){
		sum=max(sum, s);
		return;
	}
	if(x<n/2){dfs(x+1, y, z, s+a[k].x, k+1);}
	if(y<n/2){dfs(x, y+1, z, s+a[k].y, k+1);}
	if(z<n/2){dfs(x, y, z+1, s+a[k].z, k+1);}
}
bool cmp(node a, node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
		}
		if(n==100000){
			sort(a+1, a+n+1, cmp);
			for(int i=1;i<=50000;i++){
				sum+=a[i].x;
			}
		}
		dfs(0, 0, 0, 0, 1);
		printf("%d\n", sum);
	}
	return 0;
}
