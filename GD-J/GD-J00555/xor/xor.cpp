#include<iostream>//JT3都凹不出正解…迟早AFO 
using namespace std;
int n,k,a[500005],st[30][500005],dp[1001][1001];
short lg[500005];
int slove(int x,int y)//一大坨能跑的logn(?)查询 
{
	if(y<x)return 0;
	//cout<<st[lg[y-x+1]][x]<<' '<<lg[y-x+1-(1<<lg[y-x+1])]+1<<' '<<y-(1<<(lg[y-x+1-(1<<lg[y-x+1])]+1))+1<<endl;
	if((1<<lg[y-x+1])==y-x+1)return st[lg[y-x+1]][x];
	return st[lg[y-x+1]][x]^
	st[lg[y-x+1-(1<<lg[y-x+1])]+1][y-(1<<(lg[y-x+1-(1<<lg[y-x+1])]+1))+1]^
	slove(y-(1<<(lg[y-x+1-(1<<lg[y-x+1])]+1))+1,x+(1<<lg[y-x+1])-1);
}
int main()//预计60pts 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		lg[0]=-1;
		for(int i=1;i<=n;i++)lg[i]=lg[i/2]+1,st[0][i]=a[i];
		for(int i=1;i<=lg[n];i++)
		{
			for(int j=1;j<=n-(1<<i)+1;j++)
			st[i][j]=st[i-1][j]^st[i-1][j+(1<<(i-1))];
		}
		/*for(int i=0;i<=lg[n];i++)
		{
			for(int j=1;j<=n-(1<<i)+1;j++)cout<<st[i][j]<<' ';
			cout<<endl;
		}*/
		//while(1){int x,y;cin>>x>>y;cout<<slove(x,y)<<endl;}
		/*for(int i=1;i<=n;i++)//需要优化成O(nlogn)!!! 
		{
			for(int j=0;j<i;j++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(slove(j+1,i)==k)dp[i][i]=max(dp[i][i],dp[i][j]+1);
			}
		}*/
		for(int len=1;len<=n;len++)//n2logn都写炸了，只能n3了(不过预估分不变 
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;if(slove(i,j)==k)dp[i][j]=1;
				for(int k=i;k<j;k++)dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
		cout<<dp[1][n];
		return 0;
	}
	else
	{
		int ans=0,s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s+=a[i];if(a[i]%2==k)ans++,s=0;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

