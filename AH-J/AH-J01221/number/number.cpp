//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int t[15];
string s;
int main(){
	//O(9n)
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n = s.length();
    for(int i = 0;i <= n;i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			t[s[i]-'0'] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		for(int j = 1;j <= t[i];j ++) cout << i;
	}
	return 0;
}
