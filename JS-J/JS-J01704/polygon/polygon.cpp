#include<bits/stdc++.h>
using namespace std;
#define int long long
//a bag dp?
int n,a[6002],qzz[10012],k=0,ans=0;
const int MOD=998244353;
int fastpow(int base,int expo){
	int fin=1;
	while(expo){
		if(expo&1)fin=(fin*base)%MOD;
		base=base*base%MOD;
		expo>>=1;
	}
	return fin;
}
int lowbit(int x){
	return x&-x;
}
void add(int u,int val){
	//cout<<u<<" "<<val<<" ADD\n";
	while(u<=k){
		qzz[u]=(qzz[u]+val);
		u+=lowbit(u);
	}
}
int query(int u){
	//front u
	int ans=0;
	while(u){
		ans=(ans+qzz[u]%MOD)%MOD;
		u-=lowbit(u);
	}
	return ans%MOD;
}
int query_point(int u){
	if(u==0)return 0;
	return (query(u)+MOD-query(u-1))%MOD;
}
signed main(){
	//The below are freopens.
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    //Done.
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>k)k=a[i];
	}
	k+=3;
    sort(a+1,a+n+1);
    add(a[1],1);
    add(a[2],1);
    add(a[1]+a[2],1);
    for(int i=3;i<=n;i++){
		ans=(ans+query(a[i]))%MOD;
	    for(int j=k;j>=a[i]+1;j--)	{
			add(j,query_point(j-a[i]));
		}
		add(a[i],1);	
	}
	cout<<((fastpow(2,n)+MOD-2)%MOD+MOD-n-ans)%MOD;
    return 0;
}

