#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int arr[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i <= s.size() - 1;i++){
		if(s[i] >= '0' and s[i] <= '9'){
			arr[s[i]] += 1;
		}
	}
	for(int i = 60;i > 47;i--){
		for(int j = 1;j <= arr[i];j++){
			cout << i - 48; 
		}
	}
	return 0;
} 
