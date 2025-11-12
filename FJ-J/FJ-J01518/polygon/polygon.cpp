#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","r",stdout);
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i],sum=0;
		for(int j=2;j<=n-i;j++)
		{
			for(int x=i;x<=i+j;x++)
			{
				t=max(t,a[x]);
				sum+=a[x];
			}
			if(sum>2*t)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

