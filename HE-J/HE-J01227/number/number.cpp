#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt;
	string s;
	cin >> s;
	for(int i = 0;i < 9;i++){
		if(s[i] == '1'){
			cout << 1;
			break;
		}else	if(s[i] == '2'){
			cout << 2;
			break;
		}else	if(s[i] == '3'){
			cout << 3;
			break;
		}else	if(s[i] == '4'){
			cout << 4;
			break;
		}else	if(s[i] == '5'){
			cout << 5;
			break;
		}else	if(s[i] == '6'){
			cout << 6;
			break;
		}else	if(s[i] == '7'){
			cout << 7;
			break;
		}else	if(s[i] == '8'){
			cout << 8;
			break;
		}else	if(s[i] == '9'){
			cout << 9;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
