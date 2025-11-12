#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int n,m,a[MAXN],ans,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	if(k==0)
	{
		cout<<n/2<<'\n';
		return 0;
	}
	if(flag==0)
	{
		int num[2]={0};
		for(int i=1;i<=n;i++) num[a[i]]++;
		if(k==0) cout<<num[1]/2+num[0]<<'\n';
		else cout<<num[1]+num[0]/2<<'\n';
		return 0;
	}
	return 0;
}
