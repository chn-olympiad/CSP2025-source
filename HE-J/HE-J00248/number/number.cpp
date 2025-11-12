#include<bits/stdc++.h>
using namespace std;
long long n=0;
string v,r;
char s[1000006];
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(long long x=0;x<=1000006;x++)
	{
		s[x]=' ';
	}
	cin>>s;
	for(n=0;n<=1000006;n++)
	{
		if(s[n]==' ')
		{
			k=n;
		}
	}
	for(int m=0;m<k;m++)
	{
		if(s[m]=='9')
		{
			a++;
		}
		if(s[m]=='8')
		{
			b++;
		}
		if(s[m]=='7')
		{
			c++;
		}
		if(s[m]=='6')
		{
			d++;
		}
		if(s[m]=='5')
		{
			e++;
		}
		if(s[m]=='4')
		{
			f++;
		}
		if(s[m]=='3')
		{
			g++;
		}
		if(s[m]=='2')
		{
			h++;
		}
		if(s[m]=='1')
		{
			i++;
		}
		if(s[m]=='0')
		{
			j++;
		}		
	}
	for(int m=0;m<a;m++)
	{
		v=v+'9';
	}
	for(int m=0;m<b;m++)
	{
		v=v+'8';
	}
	for(int m=0;m<c;m++)
	{
		v=v+'7';
	}
	for(int m=0;m<d;m++)
	{
		v=v+'6';
	}
	for(int m=0;m<e;m++)
	{
		v=v+'5';
	}
	for(int m=0;m<f;m++)
	{
		v=v+'4';
	}
	for(int m=0;m<g;m++)
	{
		v=v+'3';
	}
	for(int m=0;m<h;m++)
	{
		v=v+'2';
	}
	for(int m=0;m<i;m++)
	{
		v=v+'1';
	}
	for(int m=0;m<j;m++)
	{
		v=v+'0';
	}
	cout<<v;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
