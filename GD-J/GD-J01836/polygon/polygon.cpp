#include<bits/stdc++.h>
using namespace std;
const long long k=998244353;
long long n,ans=0;
int a[5001];
bool vis[5001]={0};
void dfs(int sumn,int cnt,int maxn,int ci)
{
	if(cnt>=3&&sumn>maxn*2)
	{
		ans++;
		ans%=k;
	}
	if(cnt==n) return ;
	for(int i=ci;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		dfs(sumn+a[i],cnt+1,a[i],i+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,1);
	cout<<ans;
	return 0; 
}
/*
真的不会，总觉得与动规有关但就是推不出，只好写个搜索捞分。
我c++的起步较晚，在初三的时候才正式地系统地学习c++。
而现在的我已经上了高二， 在csp考试的时候，看着周围的初中生，诶~，要是当时能早点接触c++就好了。
这是我第一次参加csp，也是最后一次（我还得备战高考），希望这次能拿一等。
不会写结束语......
*/ 
