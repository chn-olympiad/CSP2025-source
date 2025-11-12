#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],ans=1;
struct node
{
  int l,r;
}q[1000005];
bool cmp(node a,node b)
{
	if(a.r==b.r) return a.l>b.l;
	else return a.r<b.r;
}
int main()
{
   freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
	 cin>>a[i];
  for(int i=1;i<=n;i++)
  {
	 for(int j=1;j<=n;j++)
	 {
		 if(i<=j)
		 {
		  if(i==j)
		  {
			if(a[i]==k)
			{
			 q[ans].l=i;
		     q[ans].r=j;
		     ans++;
			}
		  }
		   else
		   {
			  int  sum=0;
			   for(int o=i;o<=j;o++)
			   {
				   sum=sum^a[o];
			   }
			   if(sum==k)
			   {
				 q[ans].l=i;
		         q[ans].r=j;
		         ans++;
			   }
		   } 
		 }
	 }
   }
   ans--;
   sort(q+1,q+1+ans,cmp);
   int spf=1,p=q[1].l;
   for(int i=2;i<=ans;i++)
   {
	   if(q[i].l>p)
	   {
		   p=q[i].r;
		   spf++;
	   }
   }
   cout<<spf<<endl;
  return 0;
}
