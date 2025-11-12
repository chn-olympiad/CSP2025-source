#include <iostream>
#include "bits/stdc++.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define MN 100100
#define MN1 700
typedef unsigned int uint;
uint d[MN1][MN1][MN1];
uint a[MN][3];
uint n;
uint hn;

  uint mmx,mmy,mmz;
 int gd(uint x,uint y,uint z)
 {
 	if(x<=hn&&y<=hn&&z<=hn)
 	return d[x][y][z];
 	return 0;
 }
int main( ) {
//	#ifndef VEC2
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	#endif
	int t;
	scanf("%d",&t);
	for(;t--;)
{
 	uint mx=0;
		scanf("%d",&n);	  hn=n/2;
	for(int i=0;i<n;i++)
	{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);			
	}

	for(uint x=0;x<=hn;x++)
		for(uint y=0;y<=hn;y++)
			for(uint z=0;z<=hn;z++)
			{
				uint sum=x+y+z-1;
				if(sum<n)
				{
				
			 
			
				int g1=0,g2=0,g3=0;
			if(x-1u<hn)	 
			      g1=gd(x-1u,y,z)+a[sum][0];
			if(y-1u<hn)
			      g2=gd(x,y-1u,z)+a[sum][1];
			if(z-1u<hn)
				  g3=gd(x,y,z-1u)+a[sum][2];
				
				
			
				
				d[x][y][z]=max(g1 ,	max(g2 ,g3  )  ); 
				
				//	printf("%d %d %d %d\n",x,y,z ,d[x][y][z]);		
				mx=max(mx,d[x][y][z]);
			//	if(d[x][y][z]>mx)
			//	{
				
		//		mx=max,mx(d[x][y][z];
			//	mmx=x;
			//	mmy=y;
		//		mmz=z;
		//	}
			
					}
			}
//		printf("000 %d\n", d[0][0][0]);		
//		printf("100 %d\n", d[1][0][0]);		
//		printf("010 %d\n", d[0][1][0]);		
//		printf("001 %d\n", d[0][0][1]);		
//		printf("011 %d\n", d[0][1][1]);		
//		printf("101 %d\n", d[1][0][1]);		
//		printf("110 %d\n", d[1][1][0]);		
	//	printf("%d,%d,%d %d\n",mmx,mmy,mmz);		
		printf("%d\n", mx);			
}

fclose(stdin);
fclose(stdout);

	return 0;
}
