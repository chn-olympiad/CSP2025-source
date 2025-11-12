#include<bits/stdc++.h>
using namespace std;
int a[100000000];
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
	int n=s.size();
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]<'a' or s[i]>'z')
		{
			a[t]=s[i]-'0';
			t++;
		}
	 } 
	 sort(a,a+n,cmp);
	 for(int i=0;i<t;i++)
	 {
	 	cout<<a[i];
	 }
	 return 0;
 } 

