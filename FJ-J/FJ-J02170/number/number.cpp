#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i])
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
} 
