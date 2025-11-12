#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5+10;
const int INF = 0x3f3f3f3f;
//1s 512mb xor
int n,k;
int a[N],c[N]; 
int ans,sum;
bool vis[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum = 0;
	for(int i=1;i<=n;i++)
	{

		sum^=a[i];		
		sum^=k;
		a[i]^=k;
		if(sum==0||a[i]==0) 
		{
			ans++;
			sum=0;
		}
		else sum^=k;
		a[i]^=k;
	}
	cout<<ans;
}

