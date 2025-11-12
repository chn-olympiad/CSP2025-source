#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=507,mod=998244353;
char c;
ll a[N],b[N],d[N];
ll n,m,k,q,ans,cnt,sum,tot,opt,mx=-1e9,l,r,mid,x,y,z;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>c,b[i]=c-'0';
	for(ll i=1;i<=n;i++)cin>>a[i],d[i]=i;
	do{
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(b[i]&&a[d[i]]>cnt)continue;
			cnt++;
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(d+1,d+1+n));
	cout<<ans; 
	return 0;
}
