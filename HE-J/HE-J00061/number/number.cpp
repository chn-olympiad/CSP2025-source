#include<bits/stdc++.h>

using namespace std;

const int SIZN = 1e6 + 10;

int len;
char s[SIZN];
int nums[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> (s + 1);
	len = strlen(s + 1);
	for(int i = 1 ; i <= len ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			nums[s[i] - '0']++;
		}
	}
	bool flag = true;//num
	for(int i = 9 ; i >= 1 ; i--){
		for(int j = 1 ; j <= nums[i] ; j++){
			cout << i;
			flag = false;
		}
	}
	if(flag)cout << 0;
	else{
		for(int i = 1 ; i <= nums[0] ; i++)cout << 0;
	}
	return 0;
}
