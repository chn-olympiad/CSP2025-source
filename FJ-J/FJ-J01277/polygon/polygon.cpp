#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long s[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",strout);
	int n;
	cin>>n;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long maxn,ans=0;
	for(int i=1;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
			maxn=a[j];
			if((s[j]-s[i-1])>(2*maxn)){
				ans++;
				ans%=998244353;
			}
			for(int k=i+1;k>i&&k<j;k++){
				if((s[j]-s[i-1]-a[k])>(2*maxn)){
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
