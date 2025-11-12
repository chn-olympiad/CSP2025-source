#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,c[N],Mod=998244353,v[N];
long long ans;
char a[N];
long long pl(int x)
{
	long long cnt=1;
	for(int i=2;i<=x;i++)
		cnt=(cnt*i)%Mod;
	return cnt;
}
void dfs(int num,int lq,int qq)
{
	if(lq==m)
	{
		//cout<<"1\n";
		ans=(ans+pl(n-num))%Mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(v[i]==0)
		{
			v[i]=1;
			if(c[i]>qq)
			{
				if(a[i]=='1') dfs(num+1,lq+1,qq);
				else dfs(num+1,lq,qq+1);
			}
			else dfs(num+1,lq,qq+1);
			v[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(a+1);
	int flag=0;
	for(int i=1;i<=n;i++)
		if(a[i]=='0')
		{
			flag=1;
			break;
		}
	if(m==n)
	{
		if(!flag) cout<<pl(n);
		else cout<<"0";
		return 0;
	}
	if(!flag)
	{
		cout<<pl(n);
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}