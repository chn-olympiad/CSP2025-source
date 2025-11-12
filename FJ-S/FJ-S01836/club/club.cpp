#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
//每个成员都要有部门,部门可以没有成员 

LL T,n,tot;
LL ans;
LL m[N][5],mm[5];
LL cnt[5];
LL tmp_max[N],tmp[N],tmp_min[N];

bool cmp(LL a,LL b){
	return a > b;
}

void solve(){
	for(LL i = 1;i <= n;i++){
		for(LL j = 1;j <= 3;j++){
			mm[j] = m[i][j];
		}
		sort(mm + 1,mm + 1 + 3,cmp);
		//for(LL j = 1;j <= 3;j++) cout << mm[j] << " ";
		tmp_max[i] = mm[1];
		tmp[i] = mm[2];
		tmp_min[i] = mm[3];
		//cout << tmp_max[i] << " " << tmp[i] << " " << tmp_min[i] << endl;
	}
	for(LL i = 1;i <= n;i++){
		for(LL j = 1;j <= 3;j++) cnt[i] = 0;
		for(LL j = 1;j <= 3;j++){
			if(tmp_max[i] == m[i][j] && cnt[j] <= tot){
				ans += tmp_max[i];
				cnt[j]++;
			}else if(tmp[i] == m[i][j] && cnt[j] <= tot){
				ans += tmp[i];
				cnt[j]++;
			}else if(tmp_min[i] == m[i][j] && cnt[j] <= tot){
				ans += tmp_min[i];
				cnt[j]++;
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans = 0;
		scanf("%lld",&n);
		tot = n / 2;
		for(LL i = 1;i <= n;i++){
			for(LL j = 1;j <= 3;j++){
				scanf("%lld",&m[i][j]);
			}
		}
		solve();
		cout << ans << endl;
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
