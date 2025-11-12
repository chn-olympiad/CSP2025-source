#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[1000005];
long long dp[10005][10005];
bool m[100005] = {};
long long yihuo(long long a,long long b){
		return a^b;
	}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		dp[i][1] = a[i];
		//cout<<dp[i][1]<<' ';
		if(a[i]==k){
			ans = ans + 1;
			m[i] = 1;
			}
		}
	for(int i = 2;i<n;i++){
		//cout<<endl;
		for(int j = 1;j+i-1<=n;j++){
			dp[j][i] = yihuo(dp[j][i-1],a[j+i-1]);
			//cout<<dp[j][i]<<' ';
			if(dp[j][i]==k){
				bool flag = 0;
				for(int q = j;q<j+i;q++){
					if(m[q]){
						flag = 1;
						break;
						}
					}
				if(!flag){
					ans = ans + 1;
					for(int q = j;q<j+i;q++){
						m[q] = 1;
						}
					}
				}
			}
		}
	cout<<ans;
    return 0;
}
