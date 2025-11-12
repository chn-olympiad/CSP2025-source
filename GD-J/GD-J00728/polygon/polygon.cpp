#include<bits/stdc++.h>
using namespace std;
int n,r,ans;
int a[5010];
void dfs(int l,int r)
{
	int maxx=-1;
	int sum=0;
	for(int i=l;i<=r;i++) 
	{
		sum+=a[i];
		if(a[i]>=maxx) maxx=a[i];
		
	}
	
	if(r-l+1>=3&&sum>2*maxx)
	{
		ans++;
		for(int i=l;i<=r;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	
	
	if(r+1<=n) dfs(l,r+1);
	if(r+1>n&&l+1<=n) dfs(l+1,1);
	return ;
	
}
	
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	dfs(1,3);
	
	cout<<ans%998244353;
    return 0;
}

/*
不想写了，我这代码肯定有问题的，估计拿个10分都够呛。 
*/
/*
我放弃了
回想当初第一次接触编程的时候还在四年级，当初也没有打oi的打算
当初学的是python，每天做做小项目，想想还挺有成就感的
我当时是因为什么才转战c++的呢？
我好像也记不太清了
这几年物是人非，报名费都翻了一倍
我给ccf交了多少钱呢？要我算算
也陆陆续续的交了1000多块了
……
……
……
……
……
……
……
也没什么好说的了，祝愿我2026年6月能考上特长生吧…… 
 
*/
