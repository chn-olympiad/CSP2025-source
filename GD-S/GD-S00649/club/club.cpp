#include<bits/stdc++.h>
using namespace std;
#define N 101000
int n;
struct ab
{
	long long x,d;
};
struct abc
{
	int w;
	ab a1[4];
}a[N];
int abcd(ab x1,ab x2)
{
	return x1.x>x2.x;
}
int abcde(abc x1,abc x2)
{
	return x1.w<x2.w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	  {
	  	cin>>n;
	  	for(int i=1;i<=n;i++)
	  	  {
	  	    cin>>a[i].a1[1].x>>a[i].a1[2].x>>a[i].a1[3].x;
	  	    a[i].a1[1].d=1;
	  	    a[i].a1[2].d=2;
	  	    a[i].a1[3].d=3;
	  	    sort(a[i].a1+1,a[i].a1+4,abcd);
	  		a[i].w=a[i].a1[1].x-a[i].a1[2].x;
	  	  }
	  	int dd[4]={0};
	  	/*for(int i=1;i<=n;i++)
	  	  cout<<a[i].w<<endl;
	  	cout<<endl;*/
	  	sort(a+1,a+n+1,abcde);
	  	/*for(int i=1;i<=n;i++)
	  	  cout<<a[i].w<<endl;*/
	  	long long s=0;
	  	for(int i=1;i<=n;i++)
	  	  {
	  	    s=s+a[i].a1[1].x;
	  	    dd[a[i].a1[1].d]++;
	  	  }
	  	int dm=0,y=0;
	  	for(int i=1;i<=3;i++)
	  	  if(dm<dd[i])
	  	    dm=dd[i],y=i;
	  	int k=1;
	  	for(int i=1;i<=dm-(n/2);i++)
		  {
		  	while(a[k].a1[1].d!=y&&k<=n)
		  	  k++;
		  	s=s-a[k].w;
		  	k++;
		  	//cout<<k<<endl;
		  }
	  	cout<<s<<endl;
	  	//cout<<dd[1]<<" "<<dd[2]<<" "<<dd[3]<<" "<<dm<<" "<<y<<endl;
	  }
 } 
