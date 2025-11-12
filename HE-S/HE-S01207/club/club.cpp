#include<bits/stdc++.h>
using namespace std;
long long int t , n , maxn = -1;
struct node{
	long long int a , b , c;
}m[100005];
bool cmp(node a , node b){
	if(a.a == b.a){
		if(a.b == b.b){
			return a.c > b.c;
		}
		return a.b > b.b;
	}
	return a.a > b.a;
}
void dfs(long long int q , long long int sum , long long int cnt1 , long long int cnt2 , long long int cnt3){
	if(q == n + 1){
		maxn = max(maxn , sum);
		return ;
	}
	if(cnt1 <= n / 2 - 1){
		dfs(q + 1 , sum + m[q].a , cnt1 + 1 , cnt2 , cnt3);
	}
	if(cnt2 <= n / 2 - 1){
		dfs(q + 1 , sum + m[q].b , cnt1 , cnt2 + 1 , cnt3);
	}
	if(cnt3 <= n / 2 - 1 && m[q].c != 0){
		dfs(q + 1 , sum + m[q].c , cnt1 , cnt2 , cnt3 + 1);
	}
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &t);
	while(t--){
		maxn = 0;
		bool flag1 = true , flag2 = true , flag = true;
		scanf("%d" , &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d" , &m[i].a , &m[i].b , &m[i].c);
			if(m[i].b != 0){
				flag1 = false;
			}
			if(m[i].c != 0){
				flag2 = false;
			}
			if(m[i].a != 0){
				flag = false;
			}
		}
		if(flag1 && flag2){
			sort(m + 1 , m + n + 1 , cmp);
			for(int i = 1; i <= n / 2; i++){
				maxn += m[i].a;
			}
		}else if(flag2){
			dfs(1 , 0 , 0 , 0 , n / 2 + 1);
		}else if(flag1){
			dfs(1 , 0 , 0 , n / 2 + 1 , 0);
		}else if(flag){
			dfs(1 , 0 , n / 2 + 1 , 0 , 0);
		}else if(flag && flag2){
			sort(m + 1 , m + n + 1 , cmp);
			for(int i = 1; i <= n / 2; i++){
				maxn += m[i].b;
			}
		}else if(flag && flag1){
			sort(m + 1 , m + n + 1 , cmp);
			for(int i = 1; i <= n / 2; i++){
				maxn += m[i].c;
			}
		}else{
			dfs(1 , 0 , 0 , 0 , 0);
		}
		printf("%d\n" , maxn);
	}
	return 0;
}
