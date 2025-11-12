#include<bits/stdc++.h>

using namespace std;
string s;
long long ans[18];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			ans[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=ans[i];j++)
			cout<<i;
	return 0;
} 