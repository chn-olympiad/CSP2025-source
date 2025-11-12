#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],j=0;
int main()
{
	cin>>s;
	for(int i=0;i>s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	if(a[j-1]==0)
	{
		cout<<s<<endl;
	}
	return 0;
}		
