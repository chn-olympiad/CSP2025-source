#include"bits/stdc++.h"
using namespace std;
struct node{
	int a,b,c;
}cy[10010];		
int n;
bool cmp(int x,int y)
{
	return x>y;
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
		int ans=0,a1[10010],b1[10010],c1[10010];
		node cnt;
		bool f=true,fl=false;
		for(int i=0;i<n;i++)
		cin>>cy[i].a>>cy[i].b>>cy[i].c;
		for(int i=0;i<n;i++)
		{
			a1[i]=cy[i].a;
			b1[i]=cy[i].b;
			c1[i]=cy[i].c;
		}
		for(int i=0;i<n;i++) 
		{
			if(cnt.a<=n/2)
				if(a1[i]>max(b1[i],c1[i]))
					ans+=a1[i],cnt.a++;
			else if(cnt.b<=n/2)
				if(b1[i]>max(a1[i],c1[i]))
					ans+=b1[i],cnt.b++;
			else if(cnt.c<=n/2)
				if(c1[i]>max(a1[i],b1[i]))
					ans+=c1[i],cnt.c++;
		}
		cout<<ans<<endl;
	 } 
	return 0;
 } 
