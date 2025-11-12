#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int ret1[1000000];
int ret2[1000000];
int ret3[1000000];
int ret4[1000000];
int ret5[1000000];
int ret6[1000000];
int ret7[1000000];
int ret8[1000000];
int ret9[1000000];
int ret0[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	int ret=0;
	int n1=0;
	int n2=0;
	int n3=0;
	int n4=0;
	int n5=0;
	int n6=0;
	int n7=0;
	int n8=0;
	int n9=0;
	int n0=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			n0++;
			ret0[n0]=0; 
		}
		else if(s[i]=='1')
		{
			n1++;
			ret1[n1]=1; 
		}
		else if(s[i]=='2')
		{
			n2++;
			ret2[n2]=2; 
		}
		else if(s[i]=='3')
		{
			n3++;
			ret3[n3]=3; 
		}
		else if(s[i]=='4')
		{
			n4++;
			ret4[n4]=4; 
		}
		else if(s[i]=='5')
		{
			n5++;
			ret5[n5]=5; 
		}
		else if(s[i]=='6')
		{
			n6++;
			ret6[n6]=6; 
		}
		else if(s[i]=='7')
		{
			n7++;
			ret7[n7]=7; 
		}
		else if(s[i]=='8')
		{
			n8++;
			ret8[n8]=8; 
		}
		else if(s[i]=='9')
		{
			n9++;
			ret9[n9]=9; 
		}
	}
	for(int i=1;i<=n9;i++)
	{
		cout<<ret9[i];
	}
	for(int i=1;i<=n8;i++)
	{
		cout<<ret8[i];
	}
	for(int i=1;i<=n7;i++)
	{
		cout<<ret7[i];
	}
	for(int i=1;i<=n6;i++)
	{
		cout<<ret6[i];
	}
	for(int i=1;i<=n5;i++)
	{
		cout<<ret5[i];
	}
	for(int i=1;i<=n4;i++)
	{
		cout<<ret4[i];
	}
	for(int i=1;i<=n3;i++)
	{
		cout<<ret3[i];
	}
	for(int i=1;i<=n2;i++)
	{
		cout<<ret2[i];
	}
	for(int i=1;i<=n1;i++)
	{
		cout<<ret1[i];
	}
	for(int i=1;i<=n0;i++)
	{
		cout<<ret0[i];
	}
	return 0;
} 
