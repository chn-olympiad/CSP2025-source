#include<bits/stdc++.h>
using namespace std;
string s;
int k[128];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		k[s[i]]++;
	for(int i='9';i>='0';i--)
		for(int j=0;j<k[i];j++)
			cout<<(char)i;
	return 0;
}
