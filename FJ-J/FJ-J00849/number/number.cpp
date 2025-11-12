#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int b[str.size()],c=0,d,t,i,j;
	for(i=0;i<str.size();i++)
	{
		if(str[i]<='9'&&str[i]>='0')
		{
			b[c]=str[i]-48;
			c++;
		}
	}
	d=c;
	for(i=0;i<=c;)
	{
		for(j=0;j<=c;j++)
		{
			if(b[j]<b[j+1])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;	
			}
		}
		c--;
	}
	for(i=0;i<=d;i++)
	{
		if(b[i]>=0&&b[i]<=9)
		{
			cout<<b[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
