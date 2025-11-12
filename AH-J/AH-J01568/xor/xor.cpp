
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n,k,ans,vis[N]={0},vcnt=1;
ll a[N],he[N];
bool A,B;

inline bool check(int x,int y)
{
	int pos=lower_bound(vis+1,vis+1+vcnt,x)-vis;
	return 1<=pos and pos<=vcnt and vis[pos]<=y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	A=B=true;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		he[i]=he[i-1]^a[i];
		if(a[i]!=1)
			A=false;
		if(a[i]>1)
			B=false;
	}
	
	if(A)
	{
		if(k>1)
			cout<<0;
		else if(k==1)
			cout<<n;
		else if(k==0)
			cout<<n/2;
	}
	else if(B)
	{
		if(k>1)
			cout<<0;
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
				ans+=a[i];
			cout<<ans;
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
				ans+=(a[i]==0);
			for(int i=2;i<=n;i++)
				if(a[i]==1 and a[i-1]==1)
					ans++,i++;
			cout<<ans;
		}
	}
	else
	{
		for(int len=1;len<=n;len++)
		{
			for(int i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;
				if(not check(i,j) and (he[j]^he[i-1])==k)
				{
					ans++;
					for(;i<=j;i++)
						vis[++vcnt]=i;
					sort(vis+1,vis+1+vcnt);
					i=j;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
