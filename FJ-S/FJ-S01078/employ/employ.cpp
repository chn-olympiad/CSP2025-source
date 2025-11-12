#include<bits/stdc++.h>
using namespace std;
int n,m,a[526],p,b[526],t[526],o=0,ans;
char l;
void dfs(int x,int y)
{
	if(y==m)
	{
		p=1; 
		for(int i=1;i<=n-x;i++)
		{
			p*=i;
		}
		ans+=p;
		return;
	}
	if(m-y>n-x)
	{
		return;
	}
	if(x==n)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0)
		{
			t[i]=1;
			if(a[x+1]==1&&b[i]>x-y)
				dfs(x+1,y+1);
			else
				dfs(x+1,y);
			t[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		if(l=='1')
		{
			a[i]=1;
			o++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(o<m)
	{
		cout<<"0";
		return 0;
	}
	if(n<=18)
	{
		dfs(0,0);
		cout<<ans;
	}
}
/*18 6
101100110010100011
8 3 5 2 0 8 4 8 9 10 33 12 8 13 15 3 15 18
*/

















