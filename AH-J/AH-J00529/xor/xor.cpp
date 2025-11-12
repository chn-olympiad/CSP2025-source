#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int a[500005];
int n,k;
int f[500005];
int dfs(int pre)
{
	if(f[pre]!=-1) return f[pre]; 
	f[pre]=0;
	for(int i=pre+1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((a[i-1]^a[j])==k) f[pre]=max(f[pre],dfs(j)+1);
	return f[pre];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	n=read(),k=read();
	bool p1=1,p2=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]!=1) p1=0;
		if(a[i]>1) p2=0;
	}
	if(p1 && !k){write(n/2);return 0;}
	if(p2 && n>100)
	{
		if(k>1){write(0);return 0;}
		if(k==0)
		{
			for(int i=2;i<=n;i++)
				a[i]^=a[i-1];
			int ans1=0,ans2=0;
			for(int i=1;i<=n;i++) 
				if(a[i]) ans1++;
				else ans2++;
			write(max(ans1,ans2)-1);
			return 0;
		}
		for(int i=2;i<=n;i++)
			a[i]^=a[i-1];
		int ans=0;
		int x=a[1];
		for(int i=1;i<=n;i++) 
			if(x^a[i]) ans++,x=a[i];
		write(ans+a[1]);
		return 0;
	}
	for(int i=2;i<=n;i++)
		a[i]^=a[i-1];
	memset(f,-1,sizeof f);
	write(dfs(0));
	return 0;
}
