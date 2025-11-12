#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=n;i>=3;i--)
	{
		if(2*a[i]<s[i])
		{
			for(int j=0;j<=i-1;j++)
				if(s[i]-s[j]>=2*a[i])
				{
					ans++;
					ans%=998244353;
				}
		}
		else
			break;
	}
	cout<<ans;
	
	return 0;
}
