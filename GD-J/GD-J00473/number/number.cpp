#include<bits/stdc++.h>
using namespace std;
int bj[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		bj[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		while(bj[i]!=0)
		{
			cout<<i;
			bj[i]--;
		}
	}	
	return 0;
} 
