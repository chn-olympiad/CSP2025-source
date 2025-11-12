#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,s[N],c[N],p[N];
void solve1(){
	int res=1;
	for(int i=1;i<=n;i++) res=1ll*res*i%mod;
	cout<<res<<"\n";
}
void solve2(){
	int res=0;
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(!s[i]) cnt++;
		}
		//for(int i=1;i<=n;i++) cerr<<p[i]<<" ";
		//cerr<<"\n"<<cnt<<"\n";
		if(n-cnt>=m){
			res++;
			if(__builtin_expect(res>=mod,0)) res-=mod;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<res<<"\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		s[i]=ch-'0';
		flag&=(s[i]==1);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag) solve1();
	else if(m!=n) solve2();
	else cout<<flag<<"\n";
	return 0;
}