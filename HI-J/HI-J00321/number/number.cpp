#include<bits/stdc++.h>
using namespace std;
char a[1001000];
int len=0;

int o=0;
int b[110000];


int p[15];
int u=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=0;i<=10;i++)
	{
		p[i]=0;
	}
	cin>>a;
	len=strlen(a);
	//cout<<len;
	
	if(len<=100000)
	{
		for(int i=0;i<len;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				o++;
				b[o]=a[i]-'0';
			}
		}
		sort(b+1,b+o+1);
		for(int i=o;i>=1;i--)
		{
			printf("%d",b[i]);
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			if(a[i]=='0')
			{
				u++;
				p[0]++;
			}
			if(a[i]=='1')
			{
				u++;
				p[1]++;
			}
			if(a[i]=='2')
			{
				u++;
				p[2]++;
			}
			if(a[i]=='3')
			{
				u++;
				p[3]++;
			}
			if(a[i]=='4')
			{
				u++;
				p[4]++;
			}
			if(a[i]=='5')
			{
				u++;
				p[5]++;
			}
			if(a[i]=='6')
			{
				u++;
				p[6]++;
			}
			if(a[i]=='7')
			{
				u++;
				p[7]++;
			}
			if(a[i]=='8')
			{
				u++;
				p[8]++;
			}
			if(a[i]=='9')
			{
				u++;
				p[9]++;
			}
			
		}
		
		for(int i=9;i>=0;i--)
		{
			if(p[i]!=0)
			{
				for(int j=p[i];j>=1;j--)
				{
					printf("%d",i);
				}
			}
		
		}
	}
	
	return 0;
}

