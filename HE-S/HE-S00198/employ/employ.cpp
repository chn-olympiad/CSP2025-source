#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long f[10000],a[100000];
long long web(long long n){
	long long ans;
	while(n){
		ans *= n;
		n--;
		ans = ans % 998224353;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	cin >> s;
	s = ' '+s;
	for(int i = 1;i <= s.length();i++){
		if(s[i] == '1')f[i]++;
		f[i] += f[i - 1];
	}
	int nn = n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 0){
			nn--;
		}
	}
	cout << web(nn);
	
	
	
	
	return 0;
} 
