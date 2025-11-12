#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
long long y[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			y[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(y[i]--)cout<<i;
	}
	return 0;
}
