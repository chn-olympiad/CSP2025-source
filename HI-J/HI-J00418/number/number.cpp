#include<bits/stdc++.h>
using namespace std;
string s;
int n,d = 1;
int c[1005];
int cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	if(n == 1){
		cout << s;
		return 0;
	}
	for(int i = 0;i < n;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			c[d] = (int)s[i] - 48;
			d++;
		}
	}
	sort(c + 1,c + d + 1,cmp);
	for(int i = 1;i <= d;i++){
		cout << c[i];
	}
	return 0;
}
