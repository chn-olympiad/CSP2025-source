#include<bits/stdc++.h>
using namespace std;
int s[100005][4];
struct node
{
	int x,y;	
}a[100005];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
long long sum;
int n;
void so(int a1,int b1,int t,long long num)
{
	if(t==n+1)
	{
		sum=max(sum,num);
		return;
	} 
	if(a1==(n/2))
	{
		so(a1,b1+1,t+1,num+s[t][2]);
	}
	else if(b1==(n/2))
	{
		so(a1+1,b1,t+1,num+s[t][1]);
	}
	else
	{
		so(a1+1,b1,t+1,num+s[t][1]);
		so(a1,b1+1,t+1,num+s[t][2]);
	}
	return;
}
void so1(int a1,int b1,int c1,int t,long long num)
{
	if(t==n+1)
	{
		sum=max(sum,num);
		return;
	} 
	if(a1==(n/2))
	{
		so1(a1,b1+1,c1,t+1,num+s[t][2]);
		so1(a1,b1,c1+1,t+1,num+s[t][3]);
	}
	else if(b1==(n/2))
	{
		so1(a1+1,b1,c1,t+1,num+s[t][1]);
		so1(a1,b1,c1+1,t+1,num+s[t][3]);
	}
	else if(c1==(n/2))
	{
		so1(a1+1,b1,c1,t+1,num+s[t][1]);
		so1(a1,b1+1,c1,t+1,num+s[t][2]);
	}
	else
	{
		so1(a1+1,b1,c1,t+1,num+s[t][1]);
		so1(a1,b1+1,c1,t+1,num+s[t][2]);
		so1(a1,b1,c1+1,t+1,num+s[t][3]);
	}
	return;
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
		int m=n/2;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			a[i].x=s[i][1];
			a[i].y=i;
			if(s[i][2]!=0)
				f1=0;
			if(s[i][3]!=0)
				f2=0;
		}
		sum=0;
		sort(a+1,a+n+1,cmp);
		if(f1==1&&f2==1)
		{
			for(int i=1;i<=m;i++)
				sum+=a[i].x;
			cout<<sum<<endl;
			continue;
		}
		if(f2==1&&f1!=1)
		{
			so(0,0,1,0);
			cout<<sum<<endl;
			continue;
		}
		if(n==2)
		{
			int x=max(s[1][1]+s[2][2],s[1][2]+s[2][1]),y=max(s[1][3]+s[2][1],s[1][1]+s[2][3]),z=max(s[1][3]+s[2][2],s[1][2]+s[2][3]);
			cout<<max(x,max(y,z))<<endl;
			continue;
		} 
		so1(0,0,0,1,0);
		cout<<sum<<endl;	
	} 
	return 0;
}
