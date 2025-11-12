#include <bits/stdc++.h>

using namespace std;

int n = 0,match[5001] = {0};

void matchh(int x[5001],int add,int max,int site,int number,int neww)
{
	if(neww>max)
	{
		max = neww;
	}
	add+=neww;
	if(add>max*2&&number>=3)
	{
		count++;
	}
	for(int i = site+1;i<=n;i++)
	{
		matchh(x[5001],add,max,i,number+1,match[i]);
	}
}

int main()
{
	int count = 0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>match[i];
	}
	for(int i = 1;i<=n;i++)
	{
		matchh(match[5001],0,0,i,1,match[i]);
	}
	
	cout<<count;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
