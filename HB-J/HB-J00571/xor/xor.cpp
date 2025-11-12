#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,a[500010],cnt=1,mx=-1e9;

struct stu{
	ll l,r;
}b[500010];

bool cmp(stu a1,stu a2){
	if(a1.l!=a2.l) return a1.l<a2.l;
	return a1.r<a2.r;
}

void quan(ll x,ll ct,ll q){
	if(x>cnt){
		ll ans=0;
		for(int i=1;i<x;i++){
			ans++;
			if(i!=1 && b[i-1].r>b[i].l){
				return;
			}
		}
		mx=max(mx,ans);
		return;
	}
	for(int i=x;i<=q;i++){
		if(n-i<cnt-x) continue;
		if(i<=a[x-1]) continue;
		a[x]=i;
		quan(x+1,ct,cnt);
		a[i]=0;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			ll x=0;
			for(int k=j;k<=j+i-1;k++){
				x^=a[k];
			}
			if(x==k){
				b[cnt].l=j;
				b[cnt].r=j+i-1;
				cnt++;
			}
		}
	}
	cnt--;
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) quan(1,i,cnt);
	cout<<mx;
	return 0;
}
