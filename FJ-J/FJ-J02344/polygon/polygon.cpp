#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool b[5005]; 
inline int read()
{
	int x=0,q=1;
	char c=getchar();
	while(c<'0'||'9'<c)
	{
		if(c=='-') q=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*q;
 }
void dfs(int p,int w,int k,long long sum,int maxx)
{
	if(w>=k)
	{
		if(sum>2*maxx) ans++;
		return;
	} 
	for(int i=p;i<=n;i++)
	{
		if(b[i]) continue;
		b[i]=1;
		dfs(i,w+1,k,sum+a[i],max(maxx,a[i]));
		b[i]=0;
	}
	return;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=3;i<=n;i++) dfs(1,0,i,0,0);
	cout<<ans;
	return 0;
}
