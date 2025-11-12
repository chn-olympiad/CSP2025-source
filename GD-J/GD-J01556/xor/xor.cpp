#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)cout<<n/2;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)ans++;
		}
		cout<<ans;
	}
	return 0;
}
