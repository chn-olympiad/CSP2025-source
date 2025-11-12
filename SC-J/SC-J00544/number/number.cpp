#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int idx = 0, cnt = 0;
string str;
int a[MAXN];

bool cmp(const int &x, const int &y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> str;
	
	for(int i = 0; i < str.size(); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			a[idx] = (str[i]-'0');
			idx++;
		}
	}
	
	sort(a, a+idx, cmp);
	
	for(int i = 0; i < idx; i++)
		putchar(a[i]+'0');
	
	return 0;
} 