#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct da
{
	int a;
	int b;
	int c;
}stu[100005];
int ans=0;
int cnta=0,cntb=0,cntc=0;
bool cmp(da a,da b)
{
	return a.a>b.a;
}

void dfs(int x,int y)
{
	if(x==n+1)
	{
		ans=max(ans,y);
		return;
	}
	if(cnta+1<=n/2)
	{
		cnta++;
		dfs(x+1,y+stu[x].a);
		cnta--;
	}
	if(cntb+1<=n/2)
	{
		cntb++;
		dfs(x+1,y+stu[x].b);
		cntb--;
	}
	if(cntc+1<=n/2)
	{
		cntc++;
		dfs(x+1,y+stu[x].c);
		cntc--;
	}
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0)
	{
		t--;
		cin>>n;		
		for(int i=1;i<=n;i++)
		  cin>>stu[i].a>>stu[i].b>>stu[i].c;
		ans=0;
		if(n<30)dfs(1,0);
		else
		{
			bool flag=false;
			for(int i=1;i<=n;i++)
			{
				if(stu[i].b!=0||stu[i].c!=0)
				{
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
			sort(stu+1,stu+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=stu[i].a;
			}
			else cout<<0;
		}
		cout<<ans<<endl;
	}
    return 0;	
} 
