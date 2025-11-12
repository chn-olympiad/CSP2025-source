#include <bits/stdc++.h>
#include <ctime>
using namespace std;

string make(string a,string b)
{
	char ar,ay,br,by,ac,bc;
	ar=a[rand()%2];
	ay=a[rand()%2+2];
	br=b[rand()%2];
	by=b[rand()%2+2];
	ac=a[rand()%2+4];
	bc=b[rand()%2+4];
	string t="";
	t+=ar;
	t+=br;
	t+=ay;
	t+=by;
	t+=ac;
	t+=bc;
	return t;
}
string f[10001],f1[5001],f2[2501];
int cnt[8];
int main()
{
	srand(time(0));
	for(int i=1;i<=5000;i++)f[i]="RRYYCC";
	for(int i=1;i<=5000;i++)f[i+5000]="rryycc";
	
	for(int i=1;i<=5000;i++)
	{
		f1[i]=make(f[i],f[i+5000]);
	}
	for(int i=1;i<=2500;i++)
	{
		f2[i]=make(f1[i],f1[i+2500]);
		int delr=0,dely=0,delc=0;
		for(int j=0;j<=5;j++)
		{
			if(f2[i][j]=='R')delr=1;
			if(f2[i][j]=='Y')dely=1;
			if(f2[i][j]=='C')delc=1;
		}
		int sn=0;
		sn+=delc+dely+delr;
		cnt[sn]++;
		cout<<i<<" "<<f2[i]<<" "<<sn<<endl;
	}
	for(int i=3;i>=0;i--)cout<<cnt[i]<<" : ";
	
	return 0;
}
