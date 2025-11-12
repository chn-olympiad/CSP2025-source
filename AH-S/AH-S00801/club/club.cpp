#include <bits/stdc++.h>
using namespace std;
struct node{
    int c[5];
};
node a[100005];
int cnt[100005];
int club[100005];
bool cmpa(node a,node b){
	return a.c[1] >= b.c[1];
}
bool cmpb(node a,node b){
	return a.c[2] >= b.c[2];
}
int dfs(int now,int m){
	int k = -2147483647;
	if(now == m + 1){
		int ans = 0;
		for(int i = 1;i <= m;i ++) ans += a[i].c[cnt[i]];
		return ans;
	}else{
		
		for(int i = 1;i <= 3;i ++){
			if(club[i] < m/2){
				cnt[now] = i;
				club[i] ++;
				k = max(k,dfs(now + 1,m));
				club[i] --;
			} else {
				continue;
			}
		}
	}
	return k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin >> t;
	while(t --){
		bool A = 1;
        cin >> n;
        for(int i = 1;i <= n;i ++){
           for(int j = 1;j <= 3;j ++){
			   cin >> a[i].c[j];
			   if(j != 1) if(a[i].c[j] != 0) A = 0;
			}
        }
        if(A){
			int ans = 0;
			sort(a + 1,a + 1 + n,cmpa);
			for(int i = 1;i <= n / 2;i ++) ans += a[i].c[1];
			cout << ans << endl;
		}else{ 
			cout << dfs(1,n) << endl;
		}
        
	}
	return 0;
}
