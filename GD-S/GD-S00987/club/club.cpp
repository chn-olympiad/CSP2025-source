#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,f1,f2;
long long ans;
struct xi
{
	int a,b,c,t;
};
xi v[N];
bool cmp1(xi x,xi y)
{
	return x.a>y.a;
 } 
void ans2(int x,int y,int t,long long w)
{
	if(x<n/2)ans2(x+1,y,t+1,w+v[t].a);
	if(y<n/2)ans2(x,y+1,t+1,w+v[t].b);
	if(x==n/2 && y==n/2)
	{
		ans=max(ans,w);	
		return ;
	}
}
void ans1()
{
	if(f2==n)
	{
		sort(v+1,v+1+n,cmp1);
		for(int i=1;i<=n/2;i++)
			ans+=v[i].a;
		cout<<ans<<endl;
	}
	else 
	{
		ans2(0,0,1,0); 
		cout<<ans<<endl;
	}
	return ;
}
void ans3(int x,int y,int z,int t,long long w)
{
	if(x<n/2)ans3(x+1,y,z,t+1,w+v[t].a);
	if(y<n/2)ans3(x,y+1,z,t+1,w+v[t].b);
	if(z<n/2)ans3(x,y,z+1,t+1,w+v[t].c);
	if(t==n)
	{
		ans=max(ans,w);	
		return ;
	}
}
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
			v[i].t=i;
			if(!v[i].c)f1++;
			if(!v[i].b)f2++;
		}
		if(f1==n)ans1();
		else
		{
			ans3(0,0,0,1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
