#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+3;
int n,k,a[N],p[N],res,info[N],s[N];
struct node{
	int p,f,id;
}lk[N];
inline bool cmp(node x,node y){
	return x.p<y.p;
}
inline bool cmp2(node x,node y){
	return x.id<y.id;
}
void cdq(int l,int r){
	if(l==r){
		if(lk[l].p<=n) lk[l].f=max(lk[l].f,1);
		return;
	}
	int mid=(l+r)/2;
	cdq(l,mid);
	stable_sort(lk+l,lk+mid+1,cmp);
	stable_sort(lk+mid+1,lk+r+1,cmp);
	int j=l,mx=0;
	for(int i=mid+1;i<=r;++i){
		while(j<=mid&&lk[j].p<lk[i].id){
			mx=max(mx,lk[j++].f);
		}
		if(lk[i].p<=n){
			lk[i].f=max(lk[i].f,mx+1);
		}
	}
	stable_sort(lk+mid+1,lk+r+1,cmp2);
	cdq(mid+1,r);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],s[i]=(s[i-1]^a[i]);
	for(int i=n;i>=1;--i){
		info[s[i]]=i;
		p[i]=info[s[i-1]^k];
		if(!p[i]) p[i]=n+1;
	}
	for(int i=1;i<=n;++i){
		lk[i].p=p[i];
		lk[i].id=i;
	}
	cdq(1,n);
	for(int i=1;i<=n;++i) res=max(res,lk[i].f);
	cout<<res<<"\n";
	return 0;
}