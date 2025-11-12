#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=5e5+10;
ll a[N],n,k;
unordered_map<ll,bool>mp;
ll s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]),s[i]=(s[i-1]^a[i]);
	ll lst=0,ans=0;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		if(mp[s[i]^s[lst]^k]){
			ans++;
			mp.clear();
			mp[0]=1;
			lst=i;
//			cout<<i<<"\n";
		}
		else mp[s[i]^s[lst]]=1;
	}
	write(ans);
	return 0;
}
/*
结论：按顺序r越小的取尽量取

正确性显然

考虑怎么取

 
*/

