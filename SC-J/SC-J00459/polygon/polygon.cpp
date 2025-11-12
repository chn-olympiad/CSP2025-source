#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int a[N];
int n,cnt,d;
void dfs(int c,int l,int r,int w)
{
	if(c==d)
	{
		if(w>a[r]*2)cnt++;
		return;
	}
	if(r-l+1+c<d)return;
	for(int i=l;i<r;i++)
		dfs(c+1,i+1,r,w+a[i]);
		
}
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(d=1;d<=n;d++)
		for(int x=3;x<=n;x++)dfs(1,1,x,a[x]);
	cout<<cnt;
	return 0;
}