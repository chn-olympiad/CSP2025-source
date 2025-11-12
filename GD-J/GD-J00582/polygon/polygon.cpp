#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0,cnt_all=0;
void dfs(int begin,int end,int out,int num,int sum,int idx)//begin开始数字,end结束数字,out去掉的数字(编号),num数字个数,sum总和 
{
	string s;
	int maxx;
	if(end==out) 
	{
		end-=1;
		maxx=a[end-1];	
	}
	else if(begin==out)	begin+=1;
	else maxx=a[end];
	sum-=a[out];
	int end1=end;
	if(sum>maxx*2)
	{
		ans++;
		if(num>3)
		{
			if(num<=n-2) end1=2;
			if(idx==1)
				for(int j=begin;j<=end1;j++)
					dfs(begin,end,j,num-1,sum,j);
			else 
				for(int j=begin;j<=end1;j++)
					if(j!=begin)
						dfs(begin,end,j,num-1,sum,j);
			ans%=998244353;
			return ;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt_all+=a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else
	{
		dfs(1,n,0,n,cnt_all,1);
		cout<<ans;
	}
} 
