#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans=0,n,k,a[2000005];
void dfs(int l,int r)
{
	if(r>n)
	{
		l++;
		r=l;
		return ;
	}
	int s=0;
	for(int i=l;i<=r;i++)
	{
		s^=a[i];
		if(s==k)
		{
			ans++;
			l=r+1;
			r=l-1;
			break;
		}
	}
	
	dfs(l,r+1);
}
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,1);
	cout<<ans;
	return 0;
}
