#include <bits/stdc++.h>
using namespace std;
int a[505];
int s[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int maxs=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int cnt=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			unsigned long long x=s[r]-s[l-1];
			int maxx=0;
			for(int k=l;k<=r;k++)
				maxx=max(maxx,a[k]);
			if(x>maxx*2)
			{
				cout<<x<<"\n";
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
