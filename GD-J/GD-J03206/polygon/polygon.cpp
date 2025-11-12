#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],sum[5005],s,last;
const ll inf=998244353;
ll jc(ll x){
	if(x<=-1)return 0;
	if(x==0)return 1;
	if(x==1)return 1;
	return x*jc(x-1)%inf;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		last=-1;
		for(int j=1;j<=i;j++)
			if(sum[i-1]-sum[j-1]+1<=a[i]&&j>1){last=j-1;break;} 
		s+=jc(last);
		s%=inf;
	}
	cout<<s;
	return 0;
}

