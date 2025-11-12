#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,rst;
	cin>>s;
	for(int i=9;i>=0;i--) {
		for(int j=0,len=s.size();j<len;j++) {
			if(s[j] == i+'0') {
				rst+=s[j];
			}
		}
	}
	cout<<rst;
	return 0;
}
