#include<bits/stdc++.h>
using namespace std;
string s;
long long gs[15];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>s;
	long long i;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			gs[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		while(gs[i]--)
		{
			cout<<i;
		}
	}
	
	return 0;
} 
