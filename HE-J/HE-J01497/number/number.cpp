#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int M = 1000000;
	short a[M];
	int sum = 0;
	for(int i = 0;i < s.size() ;i ++){
		if (s[i] >= '0'&&s[i] <= '9'){
			a[++sum] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + sum,cmp);
	for(int i = 1;i <= sum ;i ++){
		cout << a[i];
	}
	
	return 0;
} 
