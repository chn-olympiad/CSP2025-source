#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c[N];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int sw = 1;
	for(int i = 0 ; i <= s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[sw] = s[i] - '0';
			sw++;
		}
	}
	sw--;
	sort(c + 1 , c + 1 + sw , cmp);
	for(int i = 1 ; i <= sw ; i++)cout << c[i];
	//不满分不活了 
	return 0;
}
