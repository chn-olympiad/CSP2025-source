#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
struct Node{
	int x, y, z;
}a[N];
struct Add{
	int v, id, mid;
}add[N*2];
bool cmp(Add X, Add Y){
	return X.v < Y.v;
}
int T, n, cnt[5], mx, tag[N];
bool fl[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
			fl[i] = false;
		}
		long long sum = 0; 
		int cur = 0;
		cnt[1] = 0, cnt[2] = 0, cnt[3] = 0;
		for(int i = 1; i <= n; i++){
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				sum += a[i].x;
				cnt[1]++;
				tag[i] = 1;
				add[++cur] = {a[i].x - a[i].y, 2, i};
				add[++cur] = {a[i].x - a[i].z, 3, i};
			}else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				sum += a[i].y;
				cnt[2]++;
				tag[i] = 2;
				add[++cur] = {a[i].y - a[i].x, 1, i};
				add[++cur] = {a[i].y - a[i].z, 3, i};
			}else{
				sum += a[i].z;
				cnt[3]++;
				tag[i] = 3;
				add[++cur] = {a[i].z - a[i].x, 1, i};
				add[++cur] = {a[i].z - a[i].y, 2, i};
			}
		}
		if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2){
			printf("%d\n", sum);
			continue;
		}
		if(cnt[1] > n/2){
			mx = 1;	
		}
		if(cnt[2] > n/2){
			mx = 2;	
		}
		if(cnt[3] > n/2){
			mx = 3;	
		}
		sort(add+1, add+1+cur, cmp);
		for(int i = 1; i <= cur; i++){
			if(cnt[mx] <= n/2){
				break;
			}
			if(add[i].id == mx || tag[add[i].mid] != mx || fl[add[i].mid]){
				continue;
			}
			if(cnt[add[i].id] < n/2){
				sum -= add[i].v;
				cnt[add[i].id]++;
				cnt[mx]--;
				fl[add[i].mid] = true;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
