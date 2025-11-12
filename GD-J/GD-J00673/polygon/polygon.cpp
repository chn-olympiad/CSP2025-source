#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
const int M=998244353;
int a[N],n,fl,p[N],s;
int dg(int x,int y){
	return (p[x]/p[x-y])/p[y];
	return 0;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=1;
	}
	if(fl==0){
		p[1]=1;
		for(int i=2;i<=n+1;i++){
			p[i]=(p[i-1]%M)*i%M;
			p[i]%=M;
		}
		for(int i=3;i<=n;i++){
			int t=dg(n,i);
//			cout<<t<<"\n";
			s+=t;
		}
//		cout<<1;
		cout<<s;
//		printf("%lld",s%M);
//		cout<<s%M;
		return 0;
	}else{
		int ans=0;
		int ma=max(a[1],a[2]);
		int mx=max(a[2],a[3]);
		int maxx=max(ma,mx);
		if(a[1]+a[2]+a[3]>maxx*2) ans++;
		cout<<ans;
	}
	return 0;
}
