#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 5005
#define MOD 998244353
using namespace std;
int a[N];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n;
	cin>>n;
	int man = -2e9;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		man = max(man,a[i]);
	}
	sort(a+1,a+1+n);
	if(man==1 && a[n]==1 && n>=500 && n <= 5000){
		int cnt = 2;
		int opop = 2;
		int op = 3;
		for(int i = 1; i <= n-3; i++){
			cnt = cnt*2+opop;
			opop+=op;
			op++;
		}
		cout<<(cnt-1)%MOD;
		return 0;
	}
	for(int i = 1; i <= (1<<n); i++){
		ll sum = 0;
		int cnt = 0;
		int maxn = -2e9;
		int j = i;
		int cnt_1 = n;
		while(j > 0){
			if(j&1){
				cnt++;
				sum+=a[cnt_1];
				maxn = max(maxn, a[cnt_1]);
			}
			j>>=1;
			cnt_1--;
		}
		if(cnt <= 2){
			continue;
		}
		if(sum > maxn*2){
			ans++;
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
} 
