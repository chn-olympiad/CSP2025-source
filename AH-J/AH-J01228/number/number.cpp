#include<bits/stdc++.h>
using namespace std;
string s;
int b[130];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0; i < l; i++){
		b[int(s[i])]++;
	}
	for(int i = '9'; i >= '0'; i--){
		for(int cnt = 1; cnt <= b[i]; cnt++)
			printf("%c",char(i));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
