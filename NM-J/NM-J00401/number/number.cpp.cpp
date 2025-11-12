#include<bits/stdc++.h> 
using namespace std;
bool px(int x,int y)
{
	return x>y;
}
int main()
{
	string s;
	cin>>s;
	char a[1000];
	int b=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9')
		{
			b++;
			a[i]=s[i];
		}
	}
	sort(a,a+s.size(),px);
	for(int i=0;i<b;i++)
	{
		cout<<a[i];
	}
	return 0;
}
