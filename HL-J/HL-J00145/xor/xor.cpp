#include <bits/stdc++.h>
using namespace std;
unsigned long long s[1005];
unsigned long long a[1005];
int n;
unsigned long long k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool check=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			check=false;
	}
	int ans=0;
	if(check==true&&k==0)
	{
		while(n>0)
		{
			ans+=n;
			n--;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=i;j<=n;j++)
		{
			if(x==k)
				ans++;
			x^=a[j];
		}
	}
	cout<<ans;
	return 0;
}