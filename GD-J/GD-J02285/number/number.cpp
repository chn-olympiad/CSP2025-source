#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll n = s.size();
	for(int i = 0;i < n;i++){
		char c = s[i];
		if(c >= '0' && c <= '9'){
			int num = int(c - '0');
			a[cnt++] = num;
		}
	}
	sort(a,a + cnt);
	for(int i = cnt - 1;i >= 0;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
