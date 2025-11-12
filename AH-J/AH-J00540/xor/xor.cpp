#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5*5+1;
int n,k,a[N],ans;
bool is[N];
int check(int l,int r)
{
		for(int i=l;i<=r;i++)
		{
			if(is[i]) return 0;
		}
		return 1;
}
void kkk(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		is[i]=true;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2,x;i<=n;i++)
	{
		cin>>x;
		a[i]=a[i-1]^x;
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int x=a[l-1]^a[r];
			if(x==k&&check(l,r))
			{
				ans++;
				kkk(l,r);
			}
		}
	}
	cout<<ans;
	return 0;
}
