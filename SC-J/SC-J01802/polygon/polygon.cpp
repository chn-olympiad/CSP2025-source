#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
    {
	    w=-1;
		ch=getchar();     	
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int n,ans,tx;
int a[10005],b[10005];
void solve(int dmax,int dtotal,int dx,int ds)
{
	if(dx==tx)
	{
		if(dmax*2<dtotal) 
		{
			ans++;
			return;
		}
	}
	for(int i=ds+1;i<=n;i++)
	{
		solve(max(dmax,a[i]),dtotal+a[i],dx+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=3;i<=n;i++)
	{
		tx=i;
		for(int i=1;i<=n-i+1;i++)
		{
			solve(a[i],a[i],1,i);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}