#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100],k=0;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	else
	{
		return false;
	}
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=int(s[i])-48;
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	} 
	return 0;
}