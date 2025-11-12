#include <iostream>
#include "bits/stdc++.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define MN 100100
 
typedef unsigned int uint;
 typedef long long ll;

uint n,m,k;
 

// int gd(uint x,uint y,uint z)
// {
// 	if(x<=hn&&y<=hn&&z<=hn)
// 	return d[x][y][z];
// 	return 0;
// }
#define DBG145
struct rd
{
	 int ti ;
	ll w ;
};
vector<rd> C[10010];
bool Cu[10010];
ll   Sc[20];
vector<ll> S[20];
bool Su[20];
uint   Sc_crooscnt[20];
ll   Sc_W[20];
bool sign(int a)
{
	return a>=0;
}
struct pi
{
		
 	  ll w;
	int id;

	  int lastid;
	//  bool addC;
	 ll GV()const
	 {
	 //	if(sign( t.lastid)!= sign( t.id) ) 
	 
	 	return w;
	 }
};
 struct com
 {
 	   bool operator()(const pi&A,const pi&B)
		{
				
			
			
			
		return A.GV()>B.GV();
		}
 };
 priority_queue<pi,vector<pi>,com> pp;
 
int main( ) {
//	#ifndef VEC2
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	#endif
 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
{
int a,b;ll w;
	scanf("%d%d%lld",&a,&b,&w);
	a--;b--;
	C[a].push_back({b,w});
	C[b].push_back({a,w});
	
}
for(int i=0;i<k;i++)
{
 
	scanf("%lld",&Sc[i]);
	S[i].resize(n);
  for(int ii=0;ii<n;ii++)
	{
		ll w;
			scanf("%lld",&w);
			S[i][ii]=w;
				C[ii].push_back({-i-1,w});
	}
}
#ifdef DBG 
   for(int ii=0;ii<n;ii++)
   {
   		printf("City[%d]->",ii);
   	 	 for(int i=0;i<C[ii].size();i++)
   		printf("{w=%d,id=%d}",C[ii][i].w,C[ii][i].ti);
   		printf("\n");
   }
   #endif
   #ifdef DBG2 
   for(int i=0;i<k;i++)
{
 
	printf("Sm[%d](%d)->",i, Sc[i]);
//	Sc[i]=0;
 #ifdef DBG 
  for(int ii=0;ii<n;ii++)
	{
      printf("{w=%d,id=%d}",S[i][ii] ,ii);
	}
	 #endif
		printf("\n");
}
#endif
pp.push({0,0});
ll ttc=0;
 while(!pp.empty())
{
	auto t=pp.top();
	pp.pop();

	if(t.id>=0)
		{
				if(Cu[t.id])continue;
		Cu[t.id]=true;
		}
		else
		{
			if(Su[-1-t.id])continue;
		Su[-1-t.id]=true;
		}
		if(sign( t.lastid)!= sign( t.id) ) 
		{
		int iii=-1-min(t.lastid,t.id);
		Sc_crooscnt[iii]++; 
     	Sc_W[iii]+=t.w  ;//	if(!sign( t.id))
		#ifdef DBG1
	 printf("SM %d used %d\n",iii,t.w);
	#endif
	}
	 if(!sign( t.id))
	 {
	 	//	 printf("Goto  %d\n",t.id );
	 //	if( !t.addC &&  Su[-1-t.id])ttc-=Sc[ -1-t.id ] ;	
	 }
	#ifdef DBG
	 printf("%d goto %d used %d\n",t.lastid,t.id,t.w);
	#endif
	 			ttc+=t.w;	
	if(t.id>=0)
	{
	
		for(int i=0;i<C[t.id].size();i++) 
		{				
			if(C[t.id][i].ti>=0)
			{			
				if(!Cu[C[t.id][i].ti]) 		
				{
							ll ww=		C[t.id][i].w;		
					pp.push({  ww,C[t.id][i].ti ,t.id });
				}
				
			}
			else
			{			
				if(!Su[1-C[t.id][i].ti]) 
				{
					bool usedd=Su[ -1-C[t.id][i].ti   ];
					ll ww=		C[t.id][i].w +( usedd ? 0:	Sc[ -1-C[t.id][i].ti] ) ;		
					pp.push({ww,C[t.id][i].ti, t.id    });
				}	
			}
		}
	}
	else
	{
		
	 	for(int i=0;i<n;i++) 
	 	{
	 		if(!Cu[i]  )
	 		{
			 	ll ww=		 S[-1-t.id][i];	
		
	 		pp.push({ww,  i , t.id });
			 }	
		}	 			 	
	}
	
	
}
#ifdef DBG1
printf("prev %lld\n",ttc);
#endif
   for(int i=0;i<k;i++)
{
	#ifdef DBG1
	 printf("SM %d  Cnt %d used %lld\n",i, Sc_crooscnt[i],Sc_W[i]);
	#endif
	if(Sc_crooscnt[i]==1)
	ttc-=Sc_W[i];
}

printf("%lld",ttc);
fclose(stdin);
fclose(stdout);
	return 0;
}
