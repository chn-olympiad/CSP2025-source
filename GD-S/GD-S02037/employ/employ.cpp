#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans = 1;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for(int i = 1;i <= n;i++){
		ans *= i;
	}
	ans = ans % 998244353;
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
