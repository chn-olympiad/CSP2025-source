#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const int N=1e5+91,G=5e2+5,inf=0x7fffffff;
int a[N],b[N],top=1;
int n;
ll sum;
void dfs(int x,int k,int top)
{
	if(top>=k)
	{
		int ssum=0;
		f(i,1,k)
		{
			ssum+=b[i];
		}
		if(ssum>a[x]*2) sum++;
		return;
	}
	f(i,1,x)
	{
		b[top++]=a[i];
		dfs(x,k,top);
		top--;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	f(i,1,n)
	{
		f(j,1,i)
		{
			dfs(i,j,0);
		}
	}
	cout<<sum;
	return 0;
}










































