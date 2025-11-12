#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],j=1;
bool tmp(int x,int y)
{
	return x>y;
}
int main()
{   
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
	for(int  i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a+1,a+j+1,tmp);
	for(int i=1;i<=j-1;i++)
	cout<<a[i];
}
