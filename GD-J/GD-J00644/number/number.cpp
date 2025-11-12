#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	int j = 0;
	for(int i = 1;i <= n;i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			j++;
			a[j] = s[i] - '0';
		}
	}
	sort(a+1,a+j+1);
	for(int i = j;i >= 1;i--){
		cout << a[i];
	}
	return 0;
} 
