#include<bits/stdc++.h>
/*
 * Food is delicious.
USA is a country.
Can you swim?
Kate is so big.
,
China is good.
Computer is rubbish.
Fuck CCF!!!
!!!*/
using namespace std;
typedef long long ll;
const ll N=1e6+3;
ll n,k,a[N],dp[N];
bool vis[N];
void st(int l,int r){
	for(int i=l;i<=r;i++){
		vis[i]=true;
	}
}
int mx(ll id,ll rig){
	bool bl=false;
	ll num=a[id];
	ll tmp=id-1;
	while(vis[tmp]==false){
		if(num==rig){
			bl=true;
			st(tmp,id);
			break;
		}
		num=num^a[tmp];
		tmp--;
	}
	if(num==rig){
		bl=true;
		st(tmp,id);
	}
	if(bl){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	vis[0]=true;
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[i]==k){
				dp[i]++;
			}
		}else
			dp[i]=max(dp[i-1],dp[i-1]+mx(i,k));
	}
	cout << dp[n];
	return 0;
}
