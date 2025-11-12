//GZ-S00258 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum=0,k=1;
	string s;
	cin >> n >> m;
	cin >> s;
	vector<int> a(n);
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < s.size();i++) {
		if(s[i] == '1'){
			sum++;
		}else{
			break;
		}
	}
	if(sum < m){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		k *= i;
		k %= 998244353;
	}
	cout << k;
	return 0;
}
