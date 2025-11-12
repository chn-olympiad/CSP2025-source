#include<bits/stdc++.h>
using namespace std;
string s;//,s1;
long long a[10];
long long len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[s[i]-'0']++;
		}
	}
	/*len=s1.size();
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(s1[j]<s1[j+1])
			{
				a=s1[j];
				s1[j]=s1[j+1];
				s1[j+1]=a;
			}
		}
		cout<<s1<<endl;
	}*/
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
	}
