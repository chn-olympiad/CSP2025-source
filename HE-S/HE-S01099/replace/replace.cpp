#include<bits/stdc++.h>
using namespace std;
const long long MX=5010000,INF=0x3f3f3f3f;
struct node{
	string a,b;
	long long c,l,r;
}edge[MX];

node pd(string a,string b){
	node x;
	long long len=a.size();
	x.a=" "+a;
	x.b=" "+b;
	long long pos1=0,pos2=0;
	for(long long j=1;j<=len;j++){
		if(x.a[j]=='b'){
			pos1=j;
			break;
		}
	}
	for(long long j=1;j<=len;j++){
		if(x.b[j]=='b'){
			pos2=j;
			break;
		}
	}
	x.c=pos1-pos2;
	x.l=min(pos1,pos2)-1;
	x.r=len-max(pos1,pos2);
	return  x;
}

void solve(){
	long long n,q;scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		edge[i]=pd(a,b);
		
	}
	while(q--){
		string a,b;cin>>a>>b;
		node x=pd(a,b);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			if(edge[i].c==x.c&&edge[i].l<=x.l&&edge[i].r<=x.r)  ans++;
		}
		printf("%lld\n",ans);
	}
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long T=1;
	while(T--)  solve();
	return 0;
}
