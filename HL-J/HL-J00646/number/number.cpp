#include <bits/stdc++.h>
using namespace std;
long long number[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			number[0]+=1;
		}
		if(s[i]=='1'){
			number[1]+=1;
		}
		if(s[i]=='2'){
			number[2]+=1;
		}
		if(s[i]=='3'){
			number[3]+=1;
		}
		if(s[i]=='4'){
			number[4]+=1;
		}
		if(s[i]=='5'){
			number[5]+=1;
		}
		if(s[i]=='6'){
			number[6]+=1;
		}
		if(s[i]=='7'){
			number[7]+=1;
		}
		if(s[i]=='8'){
			number[8]+=1;
		}
		if(s[i]=='9'){
			number[9]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int y=0;y<number[i];y++){
			cout << i;
		}
	}
	return 0;
}