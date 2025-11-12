#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int a[1000005],k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int lens=s.size();
	for(int i=0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	if(a[k]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
