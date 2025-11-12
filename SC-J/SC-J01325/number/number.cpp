#include <bits/stdc++.h>
using namespace std;


int v=0,k=0;
int sks,vss;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	
	string s;
	cin>>s;
	int L=100000;
	int d[100000];
	int j=0;
	for(int i=0;i<=L;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			vss=v;
			v++;
			
			
			if(s[i]==48){d[j]=0;j=j+1;}
			else
			if(s[i]==49){d[j]=1;j=j+1;}
			else
			if(s[i]==50){d[j]=2;j=j+1;}
			else
			if(s[i]==51){d[j]=3;j=j+1;}
			else
			if(s[i]==52){d[j]=4;j=j+1;}
			else
			if(s[i]==53){d[j]=5;j=j+1;}
			else
			if(s[i]==54){d[j]=6;j=j+1;}
			else
			if(s[i]==55){d[j]=7;j=j+1;}
			else
			if(s[i]==56){d[j]=8;j=j+1;}
			else
			if(s[i]==57){d[j]=9;j=j+1;}
			
			
			
			
			
			
		}
		else
		if(s[i]>='a'&&s[i]<='z')
		{
			sks=k;
			k++;
		}
		else
		break;
		
	}
	
	
	sort(d,d+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<d[i];
	}
	
	
	return 0;
}