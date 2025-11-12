#include<iostream>
#include<algorithm>
using namespace std;
int r[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s; 
	int l = s.length();
	for(int i = 0;i < l;i++){
		if(s[i] >= '0'&&s[i] <= '9'){
			int o = s[i]-'0';
			r[o]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(r[i] >= 1){
			while(r[i]){
				cout << i;
				r[i]--;
			}
		}
	}
	return 0;
}