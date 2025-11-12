#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e6+5e4+5;
int n,k,a;
int mx,s[N],t[M],f[N],ans;
int c[N];
int lowbit(int x){
	return x&(-x);
}
void update(int x,int k){
	while(x<=n){
		c[x]=max(c[x],k);
		x+=lowbit(x);
	}
	return;
}
int query(int x){
	int res=0;
	while(x){
		res=max(res,c[x]);
		x-=lowbit(x);
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		mx=max(a,mx);
		s[i]=(s[i-1]^a);
	}
	for(int i=1;i<=mx;i++)t[i]=-1;
	ans=f[1]=(s[1]==k);
	t[s[1]]=1;
	update(1,f[1]);
	for(int i=2;i<=n;i++){
		int ls=t[(s[i]^k)];
		if(ls!=-1)f[i]=query(ls)+1;
		ans=max(ans,f[i]);
		t[s[i]]=i;
		update(i,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
