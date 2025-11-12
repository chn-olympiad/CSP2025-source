#include<bits/stdc++.h>
using namespace std;
string s;
int a,b[1000005],c;
bool p(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')	
		{
			b[i]=s[i]-'0';
			c++;
		}
	}
	sort(b,b+a,p); 
	if(b[0]==0&&c!=0)
	{
	cout<<0;	
	} 
	else
	{ 
		for(int i=0;i<c;i++)
		{
			cout<<b[i];	
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 	
}
