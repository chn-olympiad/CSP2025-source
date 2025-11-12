#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
	int n, k;
	cin >>n>>k;
	if (n%2){
		cout <<0;
	}else{
		cout <<1;
	}
	return 0;
}
