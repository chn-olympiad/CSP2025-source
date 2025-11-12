#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
int s[10];
int l=0;
	
	for(int i=0;i<=1000000;i++)
	{
		cin>>l;
		int i=s[l];
		i++;
		s[l]=i
	}
	for(int i=1;i<=s[0];i++)
	{
		cout<<"0" ;
	}
	for(int i=1;i<=s[1];i++)
	{
		cout<<"1" ;
	}
	for(int i=1;i<=s[2];i++)
	{
		cout<<"2" ;
	}
	for(int i=1;i<=s[3];i++)
	{
		cout<<"3" ;
	}
	for(int i=1;i<=s[4];i++)
	{
		cout<<"4" ;
	}
	for(int i=1;i<=s[5];i++)
	{
		cout<<"5" ;
	}
	for(int i=1;i<=s[6];i++)
	{
		cout<<"6" ;
	}
	for(int i=1;i<=s[7];i++)
	{
		cout<<"7" ;
	}
	for(int i=1;i<=s[8];i++)
	{
		cout<<"8" ;
	}
	for(int i=1;i<=s[9];i++)
	{
		cout<<"9" ;
	}
	fclose(stdin);
	fclose(stdout);

return 0; } 
