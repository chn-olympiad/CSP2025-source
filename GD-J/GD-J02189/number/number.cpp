#include<bits/stdc++.h>
using namespace std;
string s;
int ans[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=s[i]-'0';
			ans[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ans[i];j++)
		{
			cout<<i;
		}
	}
	
	
	return 0;
}
