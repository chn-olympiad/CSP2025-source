#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[1000001];
	long long a=10,f=1,b=0,p=1;
	cin.getline(s,1000001);
	freopen("number.in","E",stdin);
	freopen("number.out","W",stdout);
	a=strlen(s);
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='9')
			{
				f=1;
				b+=p*9;
				p*=10;
			}
		}
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='8')
			{
				f=1;
				b+=p*8;
				p*=10;
			}
		}	
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='7')
			{
				f=1;
				b+=p*7;
				p*=10;
			}
		}		
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='6')
			{
				f=1;
				b+=p*6;
				p*=10;
			}
		}		
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='5')
			{
				f=1;
				b+=p*5;
				p*=10;
			}
		}		
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='4')
			{
				f=1;
				b+=p*4;
				p*=10;
			}
		}		
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='3')
			{
				f=1;
				b+=p*3;
				p*=10;
			}
		}	
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='2')
			{
				f=1;
				b+=p*2;
				p*=10;
			}
		}	
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='1')
			{
				f=1;
				b+=p*1;
				p*=10;
			}
		}
		for(int i=0;s[i]!='\0';i++)
		{	
			if(s[i]=='0' and f==1)
			{
				b*=10; 
			}
		}			
	
	cout<<b;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

