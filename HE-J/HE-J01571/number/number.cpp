#include<bits/stdc++.h>
using namespace std;

int a[1000005];
string s;   // 仅包含小写英文字母及数字,至少一个1-9数字
int l;      //s长度
int c;      //a数组中数的数量

int main(){
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out","w", stdout);
	cin>>s;
	l = s.size();
	for(int i = 0; i < l; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[c] = s[i] - '0';
			c++;
		}
	}
	sort(a, a+c);
	for(int i = c - 1;i >= 0; i--){
		cout<<a[i];
	}

	return 0;
}
