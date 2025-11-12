#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size();
	long long k = 0;
	for(int i = 0;i < len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++k] = s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i = k;i >= 1;i--){
		cout << a[i];
	}
	return 0;
}
