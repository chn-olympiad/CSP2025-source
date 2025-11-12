#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//1~n
const ll MAXN = 1e5+5;
ll t, n, dp[MAXN];
ll p_num[MAXN], num[4];//编号选择，社团计数； 
ll p[MAXN][5];
ll k_num(ll op){//返回最大的编号 
	if(p[op][0]>=p[op][1] && p[op][0]>=p[op][2]){
		return 0; 
	}
	else if(p[op][1]>=p[op][0] && p[op][1]>=p[op][2]){
		return 1; 
	} 
	else{
		return 2;
	}
}
ll no_tmp1(ll op){
	if(0!=op){
		return 0; 
	}
	else if(1!=op){
		return 1; 
	} 
	else{
		return 2;
	}
}
ll no_tmp2(ll op){
	if(2!=op){
		return 2; 
	}
	else if(1!=op){
		return 1; 
	} 
	else{
		return 0;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(ll i_t = 0; i_t<t; i_t++){
		cin >> n;
		for(ll i = 0; i <= 2; i++){
			num[i] = 0;
		}
		for(ll i = 0; i <= n; i++){
			p_num[i] = 0;
			dp[i] = 0;
		}
		for(ll i = 1; i <= n; i++){
			cin >> p[i][0] >> p[i][1] >> p[i][2];
		}
		for(ll i = 1; i <= n; i++){
			dp[i] = dp[i-1];
			ll tmp = k_num(i); //a 
			if(num[tmp]<n/2){
				dp[i] = max(dp[i], dp[i]+p[i][tmp]);
				num[tmp]++;
				p_num[i] = tmp;
			}//硬加 
			else{
				ll maxq = -1, maxq_num = -1;
				for(ll j = 0; j <= 2; j++){
					if(j!=tmp && p[i][j]>maxq_num){
						maxq_num = p[i][j];
						maxq = j;
					}
				}
				dp[i] = max(dp[i], dp[i]+p[i][maxq]);
				num[maxq]++;
				p_num[i] = maxq;
				//加上除了a的最大满意度 
				ll last_j = -1;//上一个替换对象j，及其所有信息点；
				maxq_num = dp[i]; 
				bool hax = false;
				ll tmp1_2; 
				for(ll j = 1; j < i; j++){
					if(p_num[j] == tmp && dp[i]+p[i][tmp]-p[i][maxq]-p[j][tmp]+p[j][no_tmp1(tmp)]>maxq_num){
						last_j = j;
						tmp1_2 = no_tmp1(tmp);
						hax = true;
						maxq_num = dp[i]+p[i][tmp]-p[j][tmp]-p[i][maxq]+p[j][no_tmp1(tmp)];
					}
					if(p_num[j] == tmp && dp[i]+p[i][tmp]-p[i][maxq]-p[j][tmp]+p[j][no_tmp2(tmp)]>maxq_num){
						last_j = j;
						tmp1_2 = no_tmp2(tmp);
						hax = true;
						maxq_num = dp[i]+p[i][tmp]-p[j][tmp]-p[i][maxq]+p[j][no_tmp2(tmp)];
					}
				}//选j替换
				if(hax == true){
					dp[i] = max(dp[i], dp[i]+p[i][tmp]-p[last_j][tmp]-p[i][maxq]+p[last_j][tmp1_2]);
					num[tmp1_2]++;
					num[maxq]--;
					p_num[i] = tmp;
					p_num[last_j] = tmp1_2;
				} 
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
} 
