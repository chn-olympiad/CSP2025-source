#include<bits/stdc++.h>
using namespace std;
long long num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
	string s;
	cin >> s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i] >= '0' && s[i] <='8'){
			num[s[i]-'0']++;
		}else if(s[i] == '9'){
			cout << 9;
		}
	}
	for(int i=8;i>=0;i--){
		while(num[i]){
			cout << i;
			num[i]--;
		}
	}
	return 0;
}
