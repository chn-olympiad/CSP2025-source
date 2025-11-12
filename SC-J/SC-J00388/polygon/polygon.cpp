#include<bits/stdc++.h> 
using namespace std;
long long n,a[5005],ans,num;
bool flag;
//void dfs(int front,int rear,int sum,int maxn,int m)
//{
//	if((front>rear)||(rear>n)||(front>n))return;
//	if((2*maxn<sum)&&(m>=3)){
//		ans++;
//		ans%=998244353;
//	}
//	dfs(front,rear+1,sum+a[rear+1],a[rear+1],m+1);
//	for(int i=front;i<=rear;i++)
//	    dfs(front,rear+1,sum+a[rear+1]-a[i],a[rear+1],m);
//	dfs(front+1,rear,sum-a[front],maxn,m-1);
//}
int jc(int a)
{
	long long cnt=1;
	for(int i=1;i<=a;i++)
	{
		cnt*=i;
		cnt%=998244353;
	}
	return cnt;
}
long long C(int a)
{
	return jc(num)/jc(a)/jc(num-a);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)flag=1;
		if(a[i]==1)num++;
		}    
	sort(a+1,a+1+n);
	if(n<3)cout<<0;
	else if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
		    cout<<1;
		else cout<<0;
	}
	else if(flag)cout<<0;
	else
	{
		for(int i=3;i<=num;i++)
		{
			ans+=C(i);
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
} 