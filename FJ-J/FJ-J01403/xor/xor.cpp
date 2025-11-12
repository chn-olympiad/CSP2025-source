#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt1=0,cnt0=0;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else cnt0++;
	}
	if(cnt1==n&&k==0) cout<<n;
	else if(cnt0==n&&k==0) cout<<n;
	else cout<<n/2;
}
