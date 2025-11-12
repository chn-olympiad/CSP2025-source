#include<bits/stdc++.h>
#define AK return
#define RK1 0
typedef long long ll;
const int N=2e5+5,mod=1e5+57;
using namespace std;
int head[N],nxt[N],key[N],val[N],tot;
int s[N];
int n,k,ans,p;
int H(ll x){
	return x%mod; 
}
int New(int u,int v){
	tot++;
	key[tot]=u;
	val[tot]=v;
	return tot;
}
int add(int it){
	int tmp=H(key[it]);
	nxt[it]=head[tmp];
	head[tmp]=it;
	return it;
}
int find(int x,int lim){
	int tmp=H(x);
	for(int y=head[tmp];y;y=nxt[y]){
		if(val[y]<lim) return -1;
		if(key[y]==x) return y;
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		s[i]=s[i-1]^tmp;
	}
	add(New(0,0));
	for(int i=1;i<=n;i++){
		int x=k^s[i];
		int tmp=find(x,p);
		if(tmp!=-1){
			ans++;
			p=i;
		}
		add(New(s[i],i));
	}
	cout<<ans;
	AK RK1;
}
