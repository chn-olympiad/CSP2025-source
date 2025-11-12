// 9:14 i pass??
// 9:15 no...
// 9:27 AC!! 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,k;
ll a[N],f[N];
map<ll,ll> mp;
map<ll,bool> is;
//异或前缀为 i 的最大下标 j
ll ch1[N],ch2[N];
ll cnt,minn=-1;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	n=read(),k=read();
	mp[0]=0;
	is[0]=1;
	for(ll i=1;i<=n;i++){
		a[i]=read();
		f[i]=a[i]^f[i-1];
        ll tail=mp[f[i]^k]+1;
		if(is[f[i]^k]&&tail>minn){
			cnt++;
			ch1[cnt]=tail,ch2[cnt]=i;
			minn=i;
		}
		mp[f[i]]=i;
		is[f[i]]=1;
	}
//	for(ll i=1;i<=cnt;i++){
//		cout<<ch1[i]<<" "<<ch2[i]<<"\n";
//	}
	cout<<cnt;
	return 0;
}
/*
4 2
2 1 0 3

4 0
2 1 0 3

4 3
2 1 0 3

4 4
2 1 0 3

*/