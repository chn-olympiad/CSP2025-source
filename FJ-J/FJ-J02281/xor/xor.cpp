#include <bits/stdc++.h>
using namespace std; 

struct ip{
	int l,r;
};

bool cmp(ip a,ip b) {
	return a.r < b.r;
}

const int MAXN = 5e5 + 5;
int n,k; 
int a[MAXN];
int dp[MAXN];
vector<ip> v;





int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	a[0] = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		a[i] ^= a[i - 1];
	} 
	
	int sum = 0;

	
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			int ans = a[j] ^ a[i - 1];
			if(ans == k) {
				ip x;
				x.l = i;
				x.r = j;
				v.push_back(x);
			}
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	
	//for(int i = 0;i < v.size();i++) cout << v[i].r << " ";
	
	for(int i = 1;i <= n;i++) {
		dp[i] = dp[i - 1];
		//for(int j = 1;j <= i;j++) dp[i] = max(dp[i],dp[j]);
		for(int j = 0;j < v.size();j++) {
			int l = v[j].l;
			int r = v[j].r;	
			
			if(i == r) dp[i] = max(dp[i],dp[l - 1] + 1);
		}
		//int ans = num_erfen(i);
		//while(ans < v.size() && v[ans].r == i) ans++,dp[i] = max(dp[i],dp[v[ans].l - 1] + 1);
	}
	//for(int i = 1;i <= n;i++) cout << dp[i] << "  ";
	//cout << endl;
	printf("%d",dp[n]);
}
