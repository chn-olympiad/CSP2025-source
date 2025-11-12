#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
typedef long long ll;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int maxn = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(a[i],maxn);
	}
	
	if(maxn < k){
		cout << 0;
		return 0;
	}
	
	int ans = 0;
	
	int b = 1;//从哪一个位置开始 
	
	for(int i = 1;i <= n;i++){//区间右端点 
		int val = a[i];
		if(val == k){
			ans++;
			b = i + 1;
			continue;
		}
		for(int j = i - 1;j >= b;j--){//从i往左扫，找可行区间 
			val ^= a[j];
			//cout << i << ' ' << j << ' ' << val << '\n';
			if(val == k){
				ans++;
				b = i + 1;//更新扫描区间 
			}
		}
	}
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

