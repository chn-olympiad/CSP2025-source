#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string  a[N],b[N];
int c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >='0'&&s[i] <= '9'){
			a[cnt] = s[i];
			cnt++;
		}
	}
	sort(a,a+1+cnt);
	for(int i = cnt;i >=0;i--){
		cout << a[i];
	}
	return 0;
} 
