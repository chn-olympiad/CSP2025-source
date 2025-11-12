#include<iostream>
using namespace std;
string n;
int a[10]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9') a[n[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	
	return 0;
 } 
