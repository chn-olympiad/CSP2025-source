#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=5010;
int n;
int a[N];
ll ch[5010];
ll ans=0;
ll modd=998244353;
void chu()
{
	ch[0]=1;
	for(int i=1;i<=5000;i++)
	{
		ch[i]=ch[i-1]*i;
	}
	return;
}
void calc(int )
void work(int maxn,int now)
{
	int sum=maxn;
	maxn*=2;
	for(int l=1;l<now;l++)
	{
		sum=maxn/2;
		for(int r=l;r<now;r++)
		{
			if(sum>maxn)
			{
				ll ri=0;
				for(int t=1;t<=now-r;t++)
				{
					ri+=ch[now-r]/(ch[t]*ch[now-r-t]);
					ri%=modd;
				}
				cout<<now<<"/"<<l<<" "<<r<<" "<<ri<<endl;
				ans+=ri%modd;
				ans%=modd;
				break;
			}
			sum+=a[r];
		}
	}
}
int main()
{
	chu();
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		work(a[i],i);
	cout<<ans; 
	return 0;
}
