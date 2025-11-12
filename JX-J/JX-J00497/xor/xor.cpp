#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],xora[500010],finda,ans,maxf = 0;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		xora[i] = xora[i - 1] ^ a[i];
	} 
	vector <vector<int> > tong(1100000);
	for(int i = 1;i <= n;i ++){
		
		tong[xora[i]].push_back(i);
		finda = xora[i] ^ k;
		if(a[i] == k){
			ans ++;
			maxf = i;
			continue;
		}
		if(finda == 0 && maxf == 0){
			ans ++;
			maxf = i;
			continue;
		}
		if(tong[finda].empty()) continue;
		for(int j : tong[finda]){
			if(j >= maxf && j != i){
				maxf = i;
				ans ++;
				break;
			}
			else tong[finda].pop_back();
		}
	}
	cout << ans << '\n';
	return 0;
}

/*
begin time 18:30
end time 22:00

rp++
*/
