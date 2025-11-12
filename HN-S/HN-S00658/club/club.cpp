#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N][5],f[N],cnt = 0;
inline bool cmp(int u , int v){
	return u > v;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		queue<int>q1,q2,q3;
		int num1 = 0,num2 = 0,num3 = 0,sum = 0;
		for(int i = 1;i <= n;i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int ma = max(a[i][1] , max(a[i][2] , a[i][3])); 
			if(a[i][1] == ma){
				num1 ++;
				q1.push(i);
			}
			else if(a[i][2] == ma){
				num2 ++;
				q2.push(i);
			}
			else{
				num3 ++;
				q3.push(i);
			}
			sum += ma;
		}
		cnt = 0;
		if(num1 > n / 2){
			for(int i = 1;i <= num1;i ++){
				int t = q1.front();
				q1.pop();
				f[++ cnt] = max(a[t][2] , a[t][3]) - a[t][1];
			}
		}
		if(num2 > n / 2){
			for(int i = 1;i <= num2;i ++){
				int t = q2.front();
				q2.pop();
				f[++ cnt] = max(a[t][1] , a[t][3]) - a[t][2];
			}
		}
		if(num3 > n / 2){
			for(int i = 1;i <= num3;i ++){
				int t = q3.front();
				q3.pop();
				f[++ cnt] = max(a[t][2] , a[t][1]) - a[t][3];
			}
		}
		sort(f + 1 , f + cnt + 1 , cmp);
		for(int i = 1;i <= cnt - (n >> 1);i ++){
			sum += f[i];
		}
		cout << sum << "\n";
	}
	return 0;
} 
