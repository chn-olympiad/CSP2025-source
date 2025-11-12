#include <bits/stdc++.h>
using namespace std;
string s ;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0 ; i < s.length(); i ++ ){
		if(int(s.at(i)) =='9'){
			num[9]++;
		}
		if(int(s.at(i)) =='8'){
			num[8]++;
		}
		if(int(s.at(i)) =='7'){
			num[7]++;
		}
		if(int(s.at(i)) =='6'){
			num[6]++;
		}
		if(int(s.at(i)) =='5'){
			num[5]++;
		}
		if(int(s.at(i)) =='4'){
			num[4]++;
		}
		if(int(s.at(i)) =='3'){
			num[3]++;
		}
		if(int(s.at(i)) =='2'){
			num[2]++;
		}
		if(int(s.at(i)) =='1'){
			num[1]++;
		}
		if(int(s.at(i)) =='0'){
			num[0]++;
		}
	}
	//for(int i = 0 ; i <= 9 ; i++)cout << num[i] << " ";
	for(int i = 9 ; i >= 0 ; i--){
		while(num[i]){
			cout << i;
			num[i]--;
		}
	}
	return 0;
}