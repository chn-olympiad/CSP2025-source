#include<bits/stdc++.h>
#define ll long long
#define jmy jiangmuyang
using namespace std;
int a[105];
int posx[105];
int posy[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int jmyn,jmym;
	cin>>jmyn>>jmym;
	for(int i=1;i<=jmyn*jmym;i++)
	{
		cin>>a[i];
	}
	int jmyr=a[1];
	sort(a+1,a+jmyn*jmym+1);
	for(int i=1;i<=jmyn*jmym/2;i++)
	{
		swap(a[i],a[jmyn*jmym-i+1]);
	}
	int cntx=0,cnty=0;
	for(int j=1;j<=jmym;j++)
	{
		for(int i=1;i<=jmyn;i++)
		{
			posx[++cntx]=j;
		}
	}
	for(int j=1;j<=jmym;j++)
	{
		for(int i=1;i<=jmyn;i++)
		{
			if(j%2==1) posy[++cnty]=i;
			else posy[++cnty]=jmyn-i+1;
		}
	}
	for(int i=1;i<=jmyn*jmym;i++)
	{
		if(a[i]==jmyr)
		{
			cout<<posx[i]<<' '<<posy[i];
			return 0;
		}
	}
	return 0;
}
