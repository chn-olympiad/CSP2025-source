#include <bits/stdc++.h>
using namespace std;
string s;
int main(int argc, char** argv) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=0;
	int b=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a++;
		}
	}
	while(a){
		a--;
		int lt=b;
		for(int i=b;i<s.size();i++){
			while(s[lt]>'9'||s[lt]<'0'){
					lt++;
					b++;
			}
			if(s[i]>='0'&&s[i]<='9'){
				if(s[lt]<s[i]){
					lt=i;
				}
			}
		}
		cout<<s[lt];
		s[lt]='a';
	}
	return 0;
}
