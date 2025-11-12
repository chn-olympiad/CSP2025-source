#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N],cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	}
	sort(a + 1,a + 1 + cnt,cmp);
	for(int i = 1;i <= cnt;i++){
		if(cnt >= 1 && a[1] == 0){
			cout << a[1];
			break;
		}
		cout << a[i];
	}
	return 0;
}
