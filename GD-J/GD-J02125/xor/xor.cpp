#include <bits/stdc++.h>

using namespace std;

int xorr(int x,int y)
{
	if(x == y)
	{
		return x;
	}
	string xx = "",yy = "";
	string result = "";
	int resultt = 0,count = 0;
	while(x != 0)
	{
		int a = x %2;
		if(a == 1)
		{
			xx = '1'+xx;
		}
		else
		{
			xx = '0'+xx;
		}
		x = x/2;
	}
	while(y != 0)
	{
		int a = y%2;
		if(a == 1)
		{
			yy = '1'+yy;
		}
		else
		{
			yy = '0'+yy;
		}
		y = y/2;
	}
	if(xx.length()>yy.length())
	{
		for(int i = 0;i<(xx.length() - yy.length());i++)
		{
			yy = '0'+yy;
		}
	}
	if(yy.length()>xx.length())
	{
		for(int i = 0;(i<yy.length() - xx.length());i++)
		{
			xx = '0'+xx;
		}
	}
	for(int i = 0;i<xx.length();i++)
	{
		if(xx[i] == yy[i])
		{
		result+='0';
	    }
	    else
	    {
	    result+='1';
		}
	}
	for(int i = result.length() - 1;i>=0;i--)
	{
		resultt+=(result[i]-'0')*pow(2,count);
		count+=1;
	}
	return resultt;
}

int n = 0,k = 0,countt = 0;
int sign[5000][5000];
int number[1000];


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>number[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			int add = number[i];
			for(int k = i;k<=j;k++)
			{
				add = xorr(add,number[k]);
			}
			if(add == k)
			{
				sign[i][j] = 1;
			}
		}
	}
	for(int i = i;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(sign[i][j] == 1)
			{
				countt++;
			}
		}
	}
	cout<<countt;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
