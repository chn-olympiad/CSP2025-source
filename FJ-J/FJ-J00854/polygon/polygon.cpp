#include<bits/stdc++.h>
using namespace std;
int n,w,a[5090],c,b[5090];
void dfs(int o,int p)
{
	if(o==w)
	{
		int r=0,maxx=INT_MIN;
		for(int i=1;i<=o;i++)
		{
			r+=b[i];
			maxx=max(maxx,b[i]);
		}
		if(r>maxx*2)
		{
			c++;
		}
	}
	else
	{
		for(int i=p+1;i<=n;i++)
		{
			o++;
			b[o]=a[i];
			dfs(o,i);
			o--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		w=i;
		dfs(0,0);
	}
	cout<<c;
	return 0;
}
