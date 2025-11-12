#include<bits/stdc++.h>
using namespace std;

const int N=5010;
int use[N],ans,n;
/*
void check(int n,int sum,int maxv,int last)
{
	if(n>3 && sum>2*maxv)//he fa
	{
		ans++;
		
		for(int i=1;i<last && use[i]!=0;i++)
		{
			int save=use[i];
			use[i]=0;
			check(n-1,sum-save,maxv,last);
			use[i]=save;
		}
		int save=use[last];
		use[last]=0;
		int nowlast,nowmaxv;
		for(int i=last;i>0;i--) 
			if(use[i]!=0) nowlast=i,nowmaxv=use[i];
		check(n-1,sum-save,nowmaxv,nowlast);
		use[last]=save;
	}
	else if(n==3 && sum>2*maxv)//he fa
	{
		ans++;
		cout<<"m1\n";
	}
	else if(n<3) return;
	else//bu he fa
	{
		int save=use[last];
		use[last]=0;
		int nowlast,nowmaxv;
		for(int i=last;i>0;i--) 
			if(use[i]!=0) nowlast=i,nowmaxv=use[i];
		check(n-1,sum-save,nowmaxv,nowlast);
		use[last]=save;
	}
	ans%=998244353;
	return;
}*/

void dfs(int now,int sum,int maxv,int used)
{
	if(used>=3 && sum>2*maxv)
	{
		cout<<sum<<' '<<maxv<<endl;
		ans++;
		ans%=998244353;
	}
	if(now>=n) return ;
	
	dfs(now+1,sum+use[now+1],use[now+1],used+1);
	dfs(now+1,sum,maxv,used);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int sum=0,maxv=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&use[i]);
		sum+=use[i];
		maxv=max(use[i],maxv);
	}
	if(n==3 && sum>2*maxv)
	{
		ans=1;
	}
	else if(n==3 && sum<=2*maxv)
	{
		ans=0;
	}
	else if(maxv==1)
	{
		for(int j=3;j<=n;j++)
		{
			int now=1;
			for(int i=0;i<j;i++)
			{
				now*=(n-i);
			}
			ans+=now;
		}
		
	}
	/*
	else
	{
		check(n,sum,maxv,n);
	}
	*/
	else
	{
		sort(use+1,use+1+n);
		dfs(0,0,0,0);
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}
