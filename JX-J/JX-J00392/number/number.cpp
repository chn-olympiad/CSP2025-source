#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size()-1;
	for(int i=0 ; i<n+1 ; i++)
	{
		if(isdigit(s[i])) a=a+s[i];
	}
	
	int m=a.size()-1;
	for(int i=0 ; i<=m+1 ; i++)
	{
		for(int j=i+1 ; j<=m+1 ; j++)
		{
			if(a[j]>a[i]) swap(a[i],a[j]);
		}
	}
	
	cout<<a<<endl;
	return 0;
}
