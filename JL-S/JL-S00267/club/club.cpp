#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int g;
	cin>>g;
	int result[g+1];
	for(int h=1;h<=g;h++)
 {
	int n,a,b,c;
	cin>>n;
	int max[n+5],diff[n+5];
	char flag[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a>=b&&a>=c)
		{
			max[i]=a;
			flag[i]='a';
			if(b>=c)
			{
				diff[i]=a-b;
			}else{
				diff[i]=a-c;
			}
		}	
		
		if(b>=c&&b>=a)
		{
			max[i]=b;
			flag[i]='b';
			if(a>=c)
			{
				diff[i]=b-a;
			}else{
				diff[i]=b-c;
			}
		}	
		
		if(c>=a&&c>=b)
		{
			max[i]=c;
			flag[i]='c';
			if(a>=b)
			{
				diff[i]=c-a;
			}else{
				diff[i]=c-b;
			}
		}	
	}
	
	int sum=0,suma=0,sumb=0,sumc=0;
	for(int j=1;j<=n;j++)
	{
		sum=sum+max[j];
	}
	
	for(int w=1;w<=n;w++)
	{
		if(flag[w]=='a')suma++;
		if(flag[w]=='b')sumb++;
		if(flag[w]=='c')sumc++;
	}
	
	int sumbig;
	char fin_flag;
	if(suma>=sumb&&suma>=sumc){sumbig=suma; fin_flag='a';}
	if(sumb>=suma&&sumb>=sumc){sumbig=sumb; fin_flag='b';}
	if(sumc>=sumb&&sumc>=suma){sumbig=sumc; fin_flag='c';}
	int fin_diff[sumbig];
	if(sumbig>=n/2)
	{
		int t=0;
		for(int z=0;z<n;z++)
		{
			if(flag[z+1]==fin_flag)
			{
				fin_diff[z-t]=diff[z+1];
			}else{t++;}	
		}
	}
	for(int e=0;e<sumbig-1;e++)
	{
		for(int f=e+1;f<sumbig;f++)
		{
			if(fin_diff[e]>fin_diff[f])
			{
				int y;
				y=fin_diff[e];
				fin_diff[e]=fin_diff[f];
				fin_diff[f]=y;
			}
		
		}
		
	}
	
	for(int s=0;s<(sumbig-n/2);s++)
	{
		sum=sum-fin_diff[s];
	}
	result[h]=sum;
 }
 
 for(int k=1;k<=g;k++)
 {
	 cout<<result[k]<<endl;
 }
	return 0;
}	
