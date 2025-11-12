#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000006
ll n,k,a[N],pre[N],cnt;
map<ll,ll>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=-1;
	for(ll i=1,r=-1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(mp[pre[i]^k]!=0&&mp[pre[i]^k]>=r) ++cnt,r=i;
		mp[pre[i]]=i;
	}
	cout<<cnt<<endl;
	return 0;
}
