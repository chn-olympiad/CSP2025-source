#include<bits/stdc++.h>
using namespace std;

bool paix(int a,int b)
{
	return a>b;
}


int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	int b[1000000]={0};
	int i=0;
	for(int j=0;j<a;j++)
	{
		if(0<=s[j]-'0'&&s[j]-'0'<=9)
		{
		b[i]=s[j]-'0';
		i++;	
		}
	}
	
	sort(b,b+i);
	for(int x=i-1;x>=0;x--)
	{
		cout<<b[x];
	}
	
	
	
	return 0;
 } 
