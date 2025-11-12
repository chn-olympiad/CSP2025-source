#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if(s.length() == 1 && s[0] >= '1' && s[0] <= '9'){
		cout << s; // very good
		return 0;
	}
	int jc[10] = {0};
	for(int i=0;i<s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			jc[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(jc[i] != 0){
			for(int j=1;j<=jc[i];j++){
				cout << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}