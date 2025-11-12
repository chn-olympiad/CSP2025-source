#include<bits/stdc++.h>
using namespace std;
int m,n,peo,fen[200005],R;
int h=1,l=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	scanf("%d",&R);
	peo=m*n;
	fen[1]=R;
	for(int i=2;i<=peo;i++)
	{
		scanf("%d",&fen[i]);
	}
	stable_sort(fen+1,fen+peo+1);
	for(int i=peo;i>=1;i--)
	{
		if(fen[i]==R) break;
		l++;
		if(l>n)
		{
			l=1;
			h++;
		}
//		printf("%d ",fen[i]);
	}
//	printf("%d",R);
	printf("%d %d",h,l);
	return 0;
 } 
 /*
 3 3
 94 95 96 97 98 99 100 93 92*/
