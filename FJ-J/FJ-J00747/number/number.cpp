#include<bits/stdc++.h>
using namespace std;
string s;
int b[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++)b[s[i]-'0']++;
	for(int i=9; i>=0; i--)while(b[i]--)cout<<i;
}
