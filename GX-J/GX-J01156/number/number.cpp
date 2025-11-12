#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000050];
int ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	if(len == 1){
		cout << s;
		return 0;
	}
	
	for(int i=0;i<=len;i++){
		a[i] = -0x3f3f3f3f;
	}
	int x = 0;
	for(int i=0;i<=len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[x] = s[i] - '0';
			x++;
		}
	}
	int m = x;
	while(m >= 0){
		int MAXn = -0x3f3f3f3f;
		for(int i=0;i<=x;i++){
			if(a[i] > MAXn){
				MAXn = a[i];
			}
		}
		ans = ans * 10 + MAXn;
	}
	cout << ans;
	return 0;
}
