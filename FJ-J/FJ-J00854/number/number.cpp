#include<bits/stdc++.h>
using namespace std;
int n,a[11],flag=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			if(i!=0)
			for(int j=1;j<=a[i];j++)
			{
				flag=1;
				cout<<i;
			}
			else if(i==0)
			{
				if(flag)
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
				}
				else if(!flag)cout<<0;
			}
		}
	}
	return 0;
} 
