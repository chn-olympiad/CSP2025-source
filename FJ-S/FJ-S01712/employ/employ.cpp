#include <iostream>
#include "bits/stdc++.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define MN 100100
 
typedef unsigned int uint;
 

uint n,m,k;
 

// int gd(uint x,uint y,uint z)
// {
// 	if(x<=hn&&y<=hn&&z<=hn)
// 	return d[x][y][z];
// 	return 0;
// }
struct rd
{
	 int ti ;
	uint w ;
};
vector<rd> C[10010];
uint   Sc[20];
vector<uint> S[20];

int main( ) {
//	#ifndef VEC2
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
//	#endif
 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
{
int a,b,w;
	scanf("%d%d%d",&a,&b,&w);
	C[a].push_back({b,w});
	C[b].push_back({a,w});
	
}
for(int i=0;i<k;i++)
{
 
	scanf("%d",&Sc[i]);
	S[i].resize(n);
  for(int ii=0;ii<n;ii++)
	{
		int w;
			scanf("%d",&w);
			S[i][ii]=w;
				C[ii].push_back({-i,w});
	}
}




	return 0;
}
