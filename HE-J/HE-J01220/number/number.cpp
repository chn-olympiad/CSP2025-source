#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[222222];
	int z=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{	
		z++;
			a[z]=s[i]-'0';
		
		}
	}
	sort(a+1,a+z+1);
	for(int i=z;i>0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
