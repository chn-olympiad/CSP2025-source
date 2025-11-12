#include<bits/stdc++.h>
using namespace std;

string ans;

int main()
{
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ans="";
	
	string s;
	
	cin>>s;
	
	int a[11]{};
	int si=s.size();
	
	for(int i=0;i<si;i++)
	{
		
		if(s[i]>='0'&&s[i]<='9')
		{
			
			a[int(s[i])-int('0')]++;
			
		}
		
	}
	
	for(int i=9;i>=0;i--)
	{
		
		for(int j=0;j<a[i];j++)
		{
			
			ans+=(i+'0');
			
		}
		
	}
	
	cout<<ans;
	
	return 0; 
	
}
