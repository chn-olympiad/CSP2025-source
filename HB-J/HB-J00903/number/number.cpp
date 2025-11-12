#include<bits/stdc++.h>
using namespace std;
int a[1000001],p=0,k;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[p]=s[i]-48;
			p++;
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(int i=0;i<p;i++)
	{
		cout<<a[i];
	}
	return 0;
}
