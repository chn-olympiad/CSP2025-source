#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),a[100010],pos=0;
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			a[pos]=s[i]-'0';
			pos++;
			if(s[i]!='0')
			{
				flag=0;
			}
		}
	}
	sort(a,a+pos,cmp);
	if(flag)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<pos;i++)
	{
		cout<<a[i];
	}
	return 0; 
} 
