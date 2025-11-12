#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long n = -1;
	long long m = s.size();
	for(int i = 0; i < m; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n++;
			a[n] = s[i] - 48;
		}
	}
	sort(a,a + n + 1,cmp);
	for(int i = 0; i <= n; i++){
		if(i == 0 && a[i] == 0){
			cout << a[i];
			return 0;
		}else{
			cout << a[i];
		}
		
	}
	return 0;
}
