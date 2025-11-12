#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,aaa,ans[500005],b[500005],i;
int bfs(int r,int k,int n)
{
  
  if (i==n){ans[aaa+1]++;return 0;}
  if(b[i])bfs(a[i+1],k,n);
  if(r^a[++i]<=k){bfs(r^a[i],k,n);i--;}
  else{aaa++;bfs(a[++i],k,n);i--;}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	i=0;
	bfs(a[i],k,n);
	for(int j=500005;j>0;j--)if(ans[j])cout<<j<<endl;
	return 0;
	
	
}

