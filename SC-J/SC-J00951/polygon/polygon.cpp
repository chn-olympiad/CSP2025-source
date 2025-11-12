#include<iostream>
using namespace std;
const int MOD=998244353;
int n,cnt;
int a[5010];
void dfs(int i,int sum,int ma,int len)
{
	
	if(sum==0)
	{
		if(len>ma*2)
		{
			cnt++;
			cnt%=MOD;
			return ;
		}
	}
	if(i>n) return ;
	dfs(i+1,sum,ma,len);
	dfs(i+1,sum-1,max(ma,a[i]),len+a[i]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i,0,0);
//		cout<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
}