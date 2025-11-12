#includde<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 24;
int n,k;
int a[maxn],sum[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	bool flag = false;
	for(int i = 2;i <= n;i++){
		if(a[i] == 1 || a[i] == 0){
			if(a[i] == 0){
				flag = true;
		}
		else{
			return 0;
		} 
	}
	if(!flag){
		cout << n / 2;
	}
	else{
		int x = 0,y = 0;
		for(int i = 1;i <= n;i++){
			x += a[i];
			y += (a[i] ^ 1);
		} 
		if(k == 1){
			cout << x << endl;
		}
		else{
			int ans = 0,flag = 0;
			for(int i = 1;i <= n;i++){
				if(flag == 1 && a[i]){
					flag = 0;
					ans++;
				}
				else if(!a[i] && !flag){
					ans++;
				} 
				else{
					if(a[i]){
						flag = 1;
					}
				}
			}
			cout << max(ans,y);
		}
	}
	return 0;
}
