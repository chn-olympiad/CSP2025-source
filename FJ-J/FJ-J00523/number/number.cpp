#include<bits/stdc++.h>
using namespace std;
string s;
int t[10],sum;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9') 
		{
			t[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
