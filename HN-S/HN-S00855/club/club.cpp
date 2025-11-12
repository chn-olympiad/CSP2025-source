#include<bits/stdc++.h>
using namespace std;
int man[100000][2];
int fina[20];
int zhi[100000];
int main(){
	int t,n,d,maxx=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	int total=0;
	for(int y=1;y<=t;y++)
	{
	for(int i=1;i<=n;i++)
	{
		for( d=0;d<=2;d++)
		{
		cin>>man[i][d];
		if(man[i][d]!=0)
		{
			zhi[i]=man[i][d];
		}
	}
	}
	
	for(int i=0;i<=n;i++)
	{
		for(int k=i;k<=n;k++)
		{
			if(zhi[k]<zhi[k+1])
			{
				zhi[k]=t;
				zhi[k]=zhi[k+1];
				zhi[k+1]=t;
			}
		}
	}
	//for(int w=0;w<n;w++)
	//cout<<zhi[w]<<endl;
	for(int g=0;g<n/2-1;g++)
	{
		total=zhi[g]+total;
	}
	fina[y]=total;
	//cout<<fina[y];
	total=0;
	memset(man,0,sizeof(man));
	memset(zhi,0,sizeof(zhi));
	}
	for(int u=1;u<=t;u++)
	{
		maxx=max(maxx,fina[u]);
	}
	cout<<maxx;
	return 0;
}

