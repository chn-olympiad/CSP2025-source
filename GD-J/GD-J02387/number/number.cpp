#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
long long num[N],cnt;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if('0' <= s[i] && s[i] <= '9'){
			num[++cnt] = s[i] - '0';
		}
	}
	sort(num + 1,num + 1 + cnt,cmp);
	for(int i = 1;i <= cnt;i++){
		printf("%lld",num[i]);
	}
	return 0;
}
