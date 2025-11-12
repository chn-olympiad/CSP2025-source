#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string str;
int b[N],c[N],n,m,ans;
bool vis[N];
void f(int x)
{
	if(x>n)
	{
		int sum1=0;
		for(int i=1;i<=n;i++)
		{
			if(i-sum1-1>=c[b[i]]||str[i-1]=='0') continue;
			sum1++;
		}
		ans+=(sum1>=m);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			b[x]=i;
			vis[i]=1;
			f(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>str;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	f(1);
	printf("%d",ans);
	return 0;
}
