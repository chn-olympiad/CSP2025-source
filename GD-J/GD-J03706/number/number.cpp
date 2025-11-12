//t1 number
#include<iostream>
#include<algorithm>
#include<string>
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
#define bf(a, b, c) for(int b = (a); b >= (c); b--)
using namespace std;
string s;
int cnt[20];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	rf(0, i, s.size() - 1){
		if(s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++;
	}
	bf(9, i, 0){
		rf(1, j, cnt[i]) cout << i;
	}
	return 0;
}
