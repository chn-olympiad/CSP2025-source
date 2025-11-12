#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 10;

string str;
int num[N], cnt;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	getline(cin, str);
	for (int i = 0; i <= (str.size() - 1); i ++){
		if (str[i] <= '9' && str[i] >= '0'){
			num[++ cnt] = str[i] - '0';
		}
	}
	
	sort(num + 1, num + 1 + cnt, cmp);
	
	for (int i = 1; i <= cnt; i ++) cout << num[i];
	
	return 0;
}
