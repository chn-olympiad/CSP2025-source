#include<bits/stdc++.h>
using namespace std;
char t[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char r;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>'0'&&s[i]<'9'||s[i]=='0'||s[i]=='9'){
			s[i]=t[i];
		}
		else{
			continue;
		}
		if(t[i]<t[i+1]){
			r=t[i];
			t[i]=t[i+1];
			t[i+1]=r;
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<t[i+1];
	}
	return 0;
}

