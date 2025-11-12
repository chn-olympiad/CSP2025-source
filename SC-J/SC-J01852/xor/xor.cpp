#include<bits/stdc++.h>
using  namespace std;
int jz(int a)
{
	string s[105];
	int i=1;
	while(a!=0)
	{
		s[i]=char(a%2);
		i++; 
		a=a/2; 
	}
	
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	cout<<jz(n);
	return 0;
}