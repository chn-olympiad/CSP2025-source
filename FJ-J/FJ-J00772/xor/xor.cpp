# include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
	if(a[i]==0)
	ans++;
	}
	else if(k==1)
	for(int i=1;i<=n;i++)
	if(a[i]==1)
	ans++;
	cout<<ans;
}