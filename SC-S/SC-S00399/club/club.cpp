#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][4];
int n;
int maxx;
int p[100005][5];
int dfs(int d,int v,int c1,int c2,int c3)
{
//	cout<<d<<" "<<v<<" "<<c1<<" "<<c2<<" "<<c3<<endl;
	if(c1>maxx||c2>maxx||c3>maxx)
	{
//		cout<<"maxx"<<endl;
		return 0;
	}	
	else if(d>n)
	{
//		cout<<"an:"<<v<<endl;
		return v;
	}
		
	else
	{
		
		return max(dfs(d+1,v+a[d][1],c1+1,c2,c3),max(dfs(d+1,v+a[d][2],c1,c2+1,c3),dfs(d+1,v+a[d][3],c1,c2,c3+1)));
		
	}
		
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		cin>>n;
		maxx=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		cout<<dfs(1,0,0,0,0)<<endl;
		
		
		
		
		
		
		
		
		
		t--;
	}
	
	return 0;
	
	
	
	
}