#include<bits/stdc++.h>
using namespace std;
int n,t,club[3],yi[10001],er[10001],san[10001],maxx,minn,a[10001][3],b[10001],da[10001],zong,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int pp=1;pp<=t;pp++)
	{
		ans=0;
	    for(int i=1;i<=n;i++)
		   {
		   	da[i]=0;
		   	b[i]=0;
		   }
	    for(int i=1;i<=club[1];i++)
		  yi[i]=0;
		for(int i=1;i<=club[2];i++)
		  er[i]=0;
		for(int i=1;i<=club[3];i++)
		  san[i]=0;
		for(int i=1;i<=3;i++)
		  club[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxx=-1;
			minn=0x3f3f3f;
			zong=0;
		    for(int j=1;j<=3;j++)
		     {
			   cin>>a[i][j];
			   if(a[i][j]>maxx) {maxx=a[i][j];da[i]=j;}
			   minn=min(minn,a[i][j]);
			   zong+=a[i][j];
		     }
		     b[i]=maxx+maxx+minn-zong;
		}//b[i]记录第一第二志愿差 
	   for(int i=1;i<=n;i++)
	     {
	     	if(club[da[i]]+1>n/2)
	          {
	          	if(da[i]==1)
				  {
				  	sort(yi+1,yi+1+club[da[i]]);
				  	if(b[i]>yi[1]) 
					  {
					  	ans=ans-yi[1]+a[i][da[i]];
					  	yi[1]=b[i];
					   } 
				   } 
				if(da[i]==2)
				  {
				  	sort(er+1,er+1+club[da[i]]);
				  	if(b[i]>er[1]) 
					  {
					  	ans=ans-er[1]+a[i][da[i]];
					  	er[1]=b[i];
					   } 
				   }
				if(da[i]==3)
				  {
				  	sort(san+1,san+1+club[da[i]]);
				  	if(b[i]>yi[1]) 
					  {
					  	ans=ans-san[1]+a[i][da[i]];
					  	san[1]=b[i];
					   } 
				   }  
			  }
			  else 
			  {
			  	club[da[i]]++;
			  	ans+=a[i][da[i]];
			  	if(da[i]==1) yi[club[da[i]]]=b[i];
			  	if(da[i]==2) er[club[da[i]]]=b[i];
				if(da[i]==3) san[club[da[i]]]=b[i];
			   } 
		 }
	cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
