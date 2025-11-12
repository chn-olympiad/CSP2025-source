#include<bits/stdc++.h>
using namespace std;
int n;
long long k,ans;
int a[500005];
long long s[500005],yi;
bool b[500005];
void wo(int x,int y)
{
	for(int i=x;i<=y;i++) b[i]=true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	b[1]=false;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	int l,r;
	for(l=1;l<=n;l++)
	{
		if(b[l]) continue;
		for(r=l;r<=n;r++)
		{
			if(b[r]) break;
			if(l==1) yi=s[r];
			else yi=s[r]^s[l-1];
			if(yi==k)
			{
				ans++;
				wo(l,r);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
