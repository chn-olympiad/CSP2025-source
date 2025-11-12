/*
 n*m
   1 2 3..m
1
2
3
:
n
 
 2 2
 98 99 100 97
 
  ‰»Î
  2 2
  99 100 97 98
  ‰≥ˆ 
  1 2
  
   100 97
   
   99  98 
   
 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,u,x,y=1,pd=1,pd2;
int v[150];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>v[i];
	int p=v[1];
	sort(v+1,v+n*m+1,cmp);
	while(u<n*m)	
	{
		u++;
		if(x==n||(x==0&&u!=1))
		{
			if(pd==-1)
				pd=1;
			else
				pd=-1;
			y++;
		}
		x+=pd;
		//cout<<x<<' '<<y<<endl;
		if(v[u]==p)
			break;
	}
	cout<<y<<' '<<x;
	cout<<' '<<v[u];
	return 0;
} 
