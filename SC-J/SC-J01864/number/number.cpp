#include<bits/stdc++.h>
using namespace std;
int g[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin>>st;
	int len=st.length();
	st='*'+st;
	for(int i=1;i<=len;i++)
		if(st[i]>='0'&&st[i]<='9') g[st[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=g[i];j++) cout<<i;
	return 0;
}