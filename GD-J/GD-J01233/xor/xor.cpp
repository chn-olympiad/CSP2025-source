#include<iostream>
using namespace std;
const int N = 500001;

int n,k,x,ma,ans,a[N],pos[N];
struct XORR{int num,r;}dp[N];

bool specialB(){
	for(int i = 1;i <= n;++i)
		if(!(!a[i] || a[i] == 1)) return false;
	return true;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i)
		cin >> a[i],ans += (a[i] == k);
	if(specialB()){
		if(k) cout << ans;
		else cout << ans + (n-ans)/2;
		return 0;
	}
	for(int i = 1;i <= n;++i)
		pos[i] = (pos[i-1] ^ a[i]);
	for(int i = 1;i <= n;++i){
		dp[i].r = dp[i-1].r;
		dp[i].num = dp[i-1].num;
		for(int j = 1;j <= i;++j)
			if((pos[i]^pos[j-1]) == k && j > dp[j].r && dp[j].num+1 > dp[i].num)
				dp[i].num = dp[j].num + 1,dp[i].r = i;
	}
	for(int i = 1;i <= n;++i)
		ma = max(ma,dp[i].num);
	cout << ma;
	return 0;
}
