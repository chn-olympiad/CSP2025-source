#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,K=1<<20|5;
int n,k,f[N],p[K];
//f(i)表示前i个数最多能凑出多少个异或值为k的
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	memset(p,-1,sizeof p);
	p[0]=0;
	for(int i=1,a,s=0;i<=n;++i){
		cin>>a;
		s^=a;
//		cout<<f[i-1]<<','<<(~p[k^s]?f[p[k^s]]+1:0)<<'['<<(k^s)<<','<<p[k^s]<<"]\n";
		f[i]=max(f[i-1],~p[k^s]?f[p[k^s]]+1:0);
		p[s]=i;
//		cout<<"f("<<i<<")="<<f[i]<<'\n';
//		cout<<"p("<<s<<")="<<s<<'\n';
	}
	cout<<f[n];
	return 0;
}