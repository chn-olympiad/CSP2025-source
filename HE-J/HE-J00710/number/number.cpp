#include <iostream>
#include <cstring>
using namespace std;
string s;
int tong[300];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i<s.size();i++){
		tong[s[i] + 0]++;
	}

	for (int i = '9'+0;i>='0'+0;i--){
		while(tong[i]){
			tong[i]--;
			cout << i - '0';
		}
	}
	cout << endl;
	
	
	
	return 0;
}
