#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 20;
int a[N],cnt = 0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i = cnt;i >= 1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
