#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int t[10]={0};
	for (int i=0;i<l;i++){
		char c=s[i];
		int num=c-48;
		if (num>=0 && num<=9) {
			t[num]++;
		}
	}
	for (int i=9;i>=0;i--){
		for (int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	return 0;
}

