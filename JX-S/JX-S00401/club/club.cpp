#include <bits/stdc++.h>
using namespace std;
int t,n,maxa,mini,am,bm,cm,sum;
struct Node
{
	int a,b,c,maxx,ma,minn,l=0;
}x[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			int sum=x[i].a+x[i].b+x[i].c;
			x[i].maxx=max(x[i].a,max(x[i].b,x[i].c));
			x[i].minn=min(x[i].a,min(x[i].b,x[i].c));
			x[i].ma=sum-x[i].maxx-x[i].minn;
		}
		//int t2=3;
		//while(t2--)
		//{
			maxa=-INT_MAX;
			bool l;
			//mini=INT_MAX;
			for(int i=1;i<=n;i++)
			{
				if(maxa<=x[i].maxx)
				{
					maxa=x[i].maxx;
					l=i;
				}
			}
			x[l].l=1;
			if(am<n/2)
			{
				sum+=maxa;
			    am++;
			}
			
			maxa=-1;
			for(int i=1;i<=n;i++)
			{
				if(maxa<=x[i].maxx&&!x[i].l)
				{
					maxa=x[i].maxx;
					l=i;
				}
			}
			x[l].l=1;
			if(bm<=n/2)
			{sum+=maxa;bm++;}
			maxa=-1;
			for(int i=1;i<=n;i++)
			{
				if(maxa<=x[i].maxx&&!x[i].l)
				{
					maxa=x[i].maxx;
					l=i;
				}
			}
			x[l].l=1;
			if(cm<=n/2)
			{sum+=maxa;cm++;}
			
			cout<<am<<" "<<bm<<" " <<cm<<endl;
			cout<<sum<<endl;
		}
	//}
	
	return 0;
}
