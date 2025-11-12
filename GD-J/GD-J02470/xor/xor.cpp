#include<bits/stdc++.h>
using namespace std;
const int N=3e6+7;
int n,k,ans;
int vis[N];
int st[N],top;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int pre=0;
	vis[0]=1;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		pre^=x;
		if(vis[pre^k])
		{
			ans++;
			pre=0;
			for(int j=1;j<=top;j++)
			{
				vis[st[j]]=0;
			}
			top=0;
			vis[0]=1;
			continue;
		}
		vis[pre]=1;
		st[++top]=pre;
	}
	cout<<ans;
}
