#include<bits/stdc++.h>
using namespace std;
long j=0;
bool cmp(int a,int b)
{
	return a>b;
	
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long num[a.size()];
	for(long i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			num[j]=int(a[i]);
			j++;
		}
		
	}
	sort(num,num+j,cmp);
	for(long i=0;i<j;i++)
	{
		char ch=num[i];
		cout<<ch;
		
	
	}
	return 0;
 } 