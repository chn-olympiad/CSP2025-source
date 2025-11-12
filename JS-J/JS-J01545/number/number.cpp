#include<bits/stdc++.h>
using namespace std;

string str;
int n[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>str;
	for(auto s:str)
		if(isdigit(s))
			n[s-'0']++;
	
	for(int i=9;i>=0;i--)
		for(int j=1;j<=n[i];j++)
			cout<<i;
	
		
	
	return 0;
}
