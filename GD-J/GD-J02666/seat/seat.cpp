#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
struct node
{
	int x,id;
}a[205];
bool cmp(node l,node r)
{
	return l.x>r.x;
}
signed main()
{
	//ccf is "good"
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout); 
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m;
   int nn=n*m;
   for(int i=1;i<=nn;i++)cin>>a[i].x,a[i].id=i;
   sort(a+1,a+1+nn,cmp);
   int x=0;
   for(int i=1;i<=nn;i++)
   {
   	  if(a[i].id==1)
   	  {
   	  	x=i;
   	  	break;
	  }
   }
   int u=x/n,t=x%n;
   if(t)u++;
   if(u%2==1)
   {
   	if(t==0) cout<<u<<" "<<n;
   	 else  cout<<u<<" "<<t;
   }
   else
   {
   	if(t==0)cout<<u<<" "<<1;
   	 else  cout<<u<<" "<<n-t+1;
   }
  return 0;
}

