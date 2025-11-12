#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	bool f = false;
	int l = s.size();
	for(int i = 0;i < l;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[s[i]-'0']++;
			if(s[i] != '0') f = true;
		}
	}
	if(!f && l != 0){
		cout << 0;
		return 0;
	}
	for(int i = 9;i >= 0;i--){
		if(a[i]!= 0){
			while(a[i]--){
				cout << i;
			}
		}
	}
	return 0;
}
