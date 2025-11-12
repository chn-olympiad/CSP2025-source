#include<bits/stdc++.h>
using namespace std;
int t; 
int n;
struct Node{
	int x,y,z;
	bool operator <(const Node &A) const{
		return x>A.x;
	}
}a[100002];
int ans=0;
void dfs(int i,int s1,int s2,int s3,int Max)
{
	if(Max>ans)
	{
		ans=Max;
	}
	if(i>n) return;
	for(int j=1;j<=3;j++)
	{
		int k=s1+s2+s3;
		if(k<=n && s1+1<=n/2)
		{
			dfs(i+1,s1+1,s2,s3,Max+a[i].x);
		}
		if(k<=n && s2+1<=n/2)
		{
			dfs(i+1,s1,s2+1,s3,Max+a[i].y);
		}
		if(k<=n && s3+1<=n/2)
		{
			dfs(i+1,s1,s2,s3+1,Max+a[i].z);
		}
		dfs(i+1,s1,s2,s3,Max);
		
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ans=0;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
	    }
	    bool ok=true;
	    for(int i=1;i<=n;i++)
	    {
	    	if(a[i].y!=0 || a[i].z!=0)
	    	{
	    		ok=false;
			}
		}
		if(ok==true)
		{
			sort(a+1,a+n+1);
			ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
		}else{
			dfs(1,0,0,0,0);
		}
		cout<<ans<<endl;
	}	
}
