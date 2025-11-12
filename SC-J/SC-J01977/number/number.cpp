#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int k;
int compare(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=int(s[i]-'0');
			k++;
		}
		else continue;
	}
	sort(a,a+k,compare);
	for(int i=0;i<k;i++)
	{
		cout<<a[i];
	}
	return 0;
}