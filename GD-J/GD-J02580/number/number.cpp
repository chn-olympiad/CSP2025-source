#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long ar[10]={};
	string n;
	cin>>n;
	long long x=n.size();
	long long k=0;
	for(int i=0;i<x;i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			ar[n[i]-'0']++;
		}                  
	}//290es1q0
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ar[i];j++)
		cout<<i;
	}
	return 0;
} 
