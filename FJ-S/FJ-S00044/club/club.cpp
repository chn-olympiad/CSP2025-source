#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
const int MAXN=100005;
int a[MAXN][4];
int chosen[4]={0,0,0,0};//3个社团都没有人 
int ans[MAXN]={};
int res=0;
void dfs(int i)
{
	if(i>n)
	{
		res=max(res,ans[n]);
		return;
	}
	if(chosen[1]>n/2 || chosen[2]>n/2 || chosen[3]>n/2) return;
	for(int j=1;j<=3;j++)
	{
		int tmp=ans[i];
		ans[i]=ans[i-1]+a[i][j];
		chosen[j]++;//尝试下一个
		dfs(i+1);
		chosen[j]--;
		ans[i]=tmp;
	}
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t)
	{
		t--;
		cin>>n;
		res=0;
		chosen[1]=chosen[2]=chosen[3]=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans[i]=0;
		}
		 
		
		dfs(1);
		cout<<res<<endl;
	}
	
	return 0;
 } 
