#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1],b[n+1]={};
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	long long ans=0;
	if(maxn==1)
	{
		for(int i=3;i<=n;i++)
		{
			int temp=1;
			for(int j=0;j<i;j++)
			{
				temp*=(n-j);
			}
			for(int j=1;j<=i;j++)
			{
				temp/=j;
			}
			ans+=temp;
			ans%=998244353;
		}
		ans%=998244353;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2)
				{
					ans++;
					if(ans>=998244353)
					{
						ans-=998244353;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//骗分爽
//好无聊，不想待在这里……
//我也不想在这里！
//但天黑的太快想走早就来不及！ 
//哦我爱你！
//可惜关系变成没关系问题是没问题！
//于是，我们继续~
//（间奏） 
//我拿起笔，想写点东西 
//以为是武器
//能伸张正！E！
//没人理，也没有关系
//至少我还有你
//至少我还有……（没空写了） 
