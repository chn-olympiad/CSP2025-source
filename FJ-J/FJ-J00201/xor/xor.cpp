#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
const ll M=2e6+10;
struct node{
	ll l,r;
}c[N];
ll n,k,a[N],sum[N],b[M],tot,ans;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(); k=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	for(ll i=1;i<=n;i++) sum[i]=(sum[i-1]^a[i]);
	memset(b,-1,sizeof(b));
	b[0]=0;
	for(ll i=1;i<=n;i++){
		ll tmp=(sum[i]^k);
		if(b[tmp]!=-1){
			tot++;
			c[tot].l=b[tmp]+1;
			c[tot].r=i;
		}
		b[sum[i]]=i;
	}
	sort(c+1,c+tot+1,cmp);
	ll r=c[1].r;
	if(tot!=0) ans=1;
//	cout<<c[1].l<<" "<<c[1].r<<endl;
	for(ll i=2;i<=tot;i++){
//		cout<<c[i].l<<" "<<c[i].r<<endl;
		if(c[i].l>r){
			ans++;
			r=c[i].r;
		} 
	}
	cout<<ans;
	return 0;
}
