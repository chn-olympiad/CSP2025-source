#include<bits/stdc++.h>
using namespace std;
string s,s1;
int t[100];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	}
	//for(int i=0; i<=9; i++)cout<<t[i]<<" ";
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=t[i]; j++) {
			s1+=i+'0';
		}
	}
	cout<<s1;
	return 0;
}//3333333333333333333333332222222222222222222222221111111111111111111111111111111111111111111111111111111111111111
