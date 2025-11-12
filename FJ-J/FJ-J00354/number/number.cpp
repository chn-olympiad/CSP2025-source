#include<bits/stdc++.h>
using namespace std;
int a[1000006]={0};
string s;
int main()
{

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[p++]=s[i]-'0';
	}
	p--;
//	for(int i=0;i<=p;i++)cout<<a[i];
//	cout<<endl;
	sort(a,a+p+1);
	for(int i=p;i>=0;i--)cout<<a[i];
	return 0;
 } 
