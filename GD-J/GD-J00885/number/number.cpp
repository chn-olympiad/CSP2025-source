#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
const int INF = 0x3f3f3f;
const int N = 1e5 + 10;
#define LL long long

string s;
int a[20];

int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	//s = ' ' + s;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == '0') a[0]++;
		if(s[i] == '1') a[1]++;
		if(s[i] == '2') a[2]++;
		if(s[i] == '3') a[3]++;
		if(s[i] == '4') a[4]++;
		if(s[i] == '5') a[5]++;
		if(s[i] == '6') a[6]++;
		if(s[i] == '7') a[7]++;
		if(s[i] == '8') a[8]++;
		if(s[i] == '9') a[9]++;
	}
	for(int i = 9 ; i >= 0 ; i--){
		for(int j = 1 ; j <= a[i] ; j++){
			printf("%d" , i);
		}
	}
	return 0;
}

/*

*/
