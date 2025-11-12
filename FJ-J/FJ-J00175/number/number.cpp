#include<bits/stdc++.h>
using namespace std;
long long shu[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			shu[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(long long j=1;j<=shu[i];j++)
			cout<<i;
	}
	return 0;
}