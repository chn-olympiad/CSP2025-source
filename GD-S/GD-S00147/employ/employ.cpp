#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)

int n,m,nt;
bool v[505];
int arr[505],cnt,sum;
bool flag[505];
int tc[505],ans;

void dfs(int ind){
	if (ind > n){
		cnt = 0;
		sum = 0;
		for(int i=1;i<=n;i++){
			if (cnt < arr[tc[i]] && v[i]){
				sum++;
			}else{
				cnt++;
			}
		}
		ans += sum >= m;
		return;
	}
	for(int i=1;i<=n;i++){
		if (!flag[i]){
			tc[ind] = i;
			flag[i] = 1;
			dfs(ind+1);
			flag[i] = 0;
		}
	}
}

int main(){
	in("employ.in");
	out("employ.out");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	dfs(1);
	printf("%d",ans); 
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
