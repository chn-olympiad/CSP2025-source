#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll i,j,n,s[5005],a[5005],x,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=1;
	for(i=1;i<=n;i++)
	{
		if(i>=3) for(j=a[i]+1;j<=5001;j++)
		{
			ans+=s[j];
			if(ans>mod) ans-=mod;
		}
		for(j=5001;j>=0;j--)
		{
			x=min(j+a[i],5001ll);
			s[x]+=s[j];
			if(s[x]>mod) s[x]-=mod;
		}
	}
	cout<<ans;
	return 0;
}
