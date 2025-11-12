#include<bits/stdc++.h>
#define max_n 100005
using namespace std;
int w;
int n;
int a[max_n][4];
int ans=0;
int vs[max_n];
struct MEMBER
{
	int ex;
	int num;
};
MEMBER a_1[max_n];
MEMBER a_2[max_n];
MEMBER a_3[max_n];
int cmp(MEMBER x,MEMBER y)
{
	return x.ex>y.ex;
}
void dfs(int t,int sum,int cnt_all,int tt_1,int tt_2,int tt_3)
{
	if(t>n||cnt_all==n)
	{
		ans=max(ans,sum);
		return;
	}
	if(tt_1<n/2)
	{
		dfs(t+1,sum+a[t][1],cnt_all+1,tt_1+1,tt_2,tt_3); 
	} 
	if(tt_2<n/2)
	{
		dfs(t+1,sum+a[t][2],cnt_all+1,tt_1,tt_2+1,tt_3); 
	}  
	if(tt_3<n/2)
	{
		dfs(t+1,sum+a[t][3],cnt_all+1,tt_1,tt_2,tt_3+1); 
	} 
	dfs(t+1,sum,cnt_all,tt_1,tt_2,tt_3); 
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>w;
	for(int i=1;i<=w;i++)
	{
		cin>>n;
		ans=0;
		bool x=true;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			a_1[j].ex=a[j][1];
			a_2[j].ex=a[j][2];
			a_3[j].ex=a[j][3];
			a_1[j].num=j;
			a_2[j].num=j;
			a_3[j].num=j;
			if(a[j][2]!=0||a[j][3]!=0)	x=false;
		}
		sort(a_1+1,a_1+1+n,cmp);
		sort(a_2+1,a_2+1+n,cmp);
		sort(a_3+1,a_3+1+n,cmp);
		if(n==2)
		{
			int qq=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			int pp=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			int vv=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			ans=max(max(qq,pp),vv);
			cout<<ans<<endl;
			continue;
		}
		if(x)
		{
			for(int j=1;j<=n/2;j++)
		    {
		    	ans=ans+a_1[j].ex; 
	    	}
	    	cout<<ans;
		}
		bool y=true;
		for(int j=1;j<=n;j++)
		{
			if(a[j][3]!=0)
			{
				y=false;
			}
	    }
		if(y)
		{
			for(int j=1;j<=n/2;j++)
	    	{
	    		vs[a_1[j].num]=1;
	     		ans=ans+a_1[j].ex;
	    	}
	    	int cnt_1=n/2;
	    	int cnt_2=0;
	    	for(int j=1;j<=n/2;j++)
	    	{
	    		if(vs[a_2[j].num]==0)
	    		{
	    			vs[a_2[j].num]=1;
	    		    ans=ans+a_2[j].ex;
	    			cnt_2++;
				}
				else
				{
					if(a[a_2[j].num][2]>a[a_2[j].num][1])
					{
						ans=ans-a[a_2[j].num][1];
						ans=ans+a_2[j].ex;
						cnt_1--;
						cnt_2++;
					}
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(vs[j]==0)
				{
					if(a[j][1]>a[j][2]&&cnt_1<n/2)
					{
						cnt_1++;
					    ans=ans+a[j][1];
					    vs[j]=1;
					}
					else if(cnt_2<n/2)
					{
						cnt_2++;
						ans=ans+a[j][2];
						vs[j]=1;
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			dfs(1,0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
