#include<bits/stdc++.h>
using namespace std;

int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	unsigned long long num[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<10000000;i++){
		if(s[i]=='\0') break;
		else if(s[i]=='0') num[0]++;
		else if(s[i]=='1') num[1]++;
		else if(s[i]=='2') num[2]++;
		else if(s[i]=='3') num[3]++;
		else if(s[i]=='4') num[4]++;
		else if(s[i]=='5') num[5]++;
		else if(s[i]=='6') num[6]++;
		else if(s[i]=='7') num[7]++;
		else if(s[i]=='8') num[8]++;
		else if(s[i]=='9') num[9]++;
		else continue;
	}
	for(int i=0;i<num[9];i++) cout << 9;
	for(int i=0;i<num[8];i++) cout << 8;
	for(int i=0;i<num[7];i++) cout << 7;
	for(int i=0;i<num[6];i++) cout << 6;
	for(int i=0;i<num[5];i++) cout << 5;
	for(int i=0;i<num[4];i++) cout << 4;
	for(int i=0;i<num[3];i++) cout << 3;
	for(int i=0;i<num[2];i++) cout << 2;
	for(int i=0;i<num[1];i++) cout << 1;
	for(int i=0;i<num[0];i++) cout << 0;
	return 0;
}