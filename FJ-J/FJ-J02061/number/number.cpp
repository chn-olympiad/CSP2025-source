#include<bits/stdc++.h>
using namespace std;
string s;
int t[10] = {0};
int main(){
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if('0' <= s[i] && '9' >= s[i]){
			int k = s[i]-'0';
			t[k]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(t[i] >= 1){
			for(int j = 1;j <= t[i];j++){
				printf("%d",i);
			}
		}
	}
	printf("\n");
	return 0;
}

