#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int b[a][3];
	for(int i=0;i<a;i++)
	{
		for(int j=0;i<3;i++)
		{
			cin>>b[i][j];
		}
	}
	int c[a],e[a],f=0,g=0,h=0,l[a],m[a],n[a];
	int d=0,k[a];
	for(int i=0;i<a;i++)
	{
		if(b[i][0]>=b[i][1]>=b[i][2])c[i]=b[i][0],e[i]=b[i][1],f++,k[i]=c-e,l[f]=i,d=d+c[i];	
		if(b[i][0]>=b[i][2]>=b[i][1])c[i]=b[i][0],e[i]=b[i][2],f++,k[i]=c-e,l[f]=i,d=d+c[i];
		if(b[i][1]>=b[i][0]>=b[i][2])c[i]=b[i][1],e[i]=b[i][0],g++,k[i]=c-e,m[g]=i,d=d+c[i];
		if(b[i][1]>=b[i][2]>=b[i][0])c[i]=b[i][1],e[i]=b[i][2],g++,k[i]=c-e,m[g]=i,d=d+c[i];
		if(b[i][2]>=b[i][0]>=b[i][1])c[i]=b[i][2],e[i]=b[i][0],h++,k[i]=c-e,n[h]=i,d=d+c[i];
		if(b[i][2]>=b[i][1]>=b[i][0])c[i]=b[i][2],e[i]=b[i][1],h++,k[i]=c-e,n[h]=i,d=d+c[i];	
	}
	int o=1000000000;
	if(f>a/2)
	{
		for(int i=0;i<f;i++)
		{
			if(k[l[i]]<=o)
				o=k[l[i]];
		}
		d=d-o;
	}
	int p=1000000000;
	if(g>a/2)
	{
		for(int i=0;i<g;i++)
		{
			if(k[m[i]]<=p)
				p=k[m[i]];
		}
		d=d-p;
	}
	int q=1000000000;
	if(h>a/2)
	{
		for(int i=0;i<h;i++)
		{
			if(k[n[i]]<=q)
				q=k[n[i]];
		}
		d=d-h;
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
