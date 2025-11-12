#include<bits/stdc++.h>
using namespace std;

int f[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			f[s[i]-'0']++;
		}
	}
	for(int i = 10; i >= 0; i--){
		if(f[i] != 0){
			for(int j = 1; j <= f[i]; j++){
				cout<<i;
			}
		}
	}
	return 0;
}

