#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int now=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[now]=s[i]-'0';
			now++;
		}
	}
	sort(a, a+now);
	for(int i=now-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}