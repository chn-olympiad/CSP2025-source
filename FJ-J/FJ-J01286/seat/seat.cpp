#include <bits/stdc++.h>
using namespace std;
struct node
{
	int soccer,id;
	
}a[10000];
bool cmp(node x,node y)
{
	return x.soccer>y.soccer;
}
int w,h,k=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>w>>h;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>a[++k].soccer; 
			a[k].id=k;
		} 
	}
	sort(a+1,a+k+1,cmp);
	int p;
	for(int i=1;i<=k;i++)
	{
		if(a[i].id==1)
		{
			p=i;
		}
	}
	
	int w1=p/h,h1,pp=0;
	//cout<<p<<" "<<p/h<<" "<<p%h<<" "<<w1%2<<" ";//p=4,w=2,h=2
	if(p%h>0)
	{
		w1++;
		h1=p%h;
		pp=1;
	}
	else
	{
		h1=h;
	}
	
	if(w1%2==0)
	{
		if(pp==1)
		{
			h1-=1;
		}
		else
		{
			h1-=h;
		}
		cout<<w1<<" "<<h-h1;
	}
	else
	{
		cout<<w1<<" "<<h1;
	}
	
	return 0;
}
//    1  2
//1 100 97
//2  99 98


