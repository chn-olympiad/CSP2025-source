#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout") ;
	string s;
	int m[100];
	long long n=0,temp=0;
	cin>>s;
	for(int i=0;i<10;i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			m[n]=s[i];
			n++;
			
		} 
	}
	for(int i=1;i<10;i++)
	{
		if(m[i]>m[i-1])
		{
			temp=m[i-1];
			m[i-1]=m[i];
			m[i]=m[i-1];	
			
		} 
	}
	for(int i=1;i<10;i++)
	{
		cout<<m[i];
	}
	return 0;
}

