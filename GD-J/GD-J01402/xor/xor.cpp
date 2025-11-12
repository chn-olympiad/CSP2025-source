#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int K=2e6+5;
int p[N],a[N],n,k,tot=0,mp[K];
struct node{
	int l,r;
	bool operator<(node t)const{
		if(r!=t.r) 
			return r<t.r;
		return l>t.l;
	}
}q[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	p[0]=0;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=(a[i]^p[i-1]);
		if(mp[(p[i]^k)]){
			q[++tot]={mp[(p[i]^k)],i};
		}
		mp[p[i]]=i+1;
	}
	sort(q+1,q+tot+1);
	int r=0,ans=0;
	for(int i=1;i<=tot;i++){
		if(q[i].l>r){
			r=q[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}