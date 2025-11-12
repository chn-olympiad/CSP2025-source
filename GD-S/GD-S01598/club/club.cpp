#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int f[2][105][105][105],n,a[N],b[N],c[N],ans,g[2][105][105];
void up(int *p,int c){
	*p=max(*p,c);
}
void calc(){
	ans=-1e9;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	memset(f,0xc0,sizeof f);
	f[0][0][0][0]=0;
	for(int i=1;i<=n;i++){
		memset(f[i%2],0xc0,sizeof f[i%2]);
		for(int sa=0;sa<=n/2;sa++)
		for(int sb=0;sb<=n/2;sb++)
		for(int sc=0;sc<=n/2;sc++){
			int *p=&f[i%2][sa][sb][sc];
			if(sa-1>=0)up(p,f[(i-1)%2][sa-1][sb][sc]+a[i]);
			if(sb-1>=0)up(p,f[(i-1)%2][sa][sb-1][sc]+b[i]);
			if(sc-1>=0)up(p,f[(i-1)%2][sa][sb][sc-1]+c[i]);
			ans=max(ans,*p);
		}
	}
	cout<<ans<<endl;
}
void calc2(){
	ans=-1e9;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	memset(g,0xc0,sizeof g);
	g[0][0][0]=0;
	for(int i=1;i<=n;i++){
		memset(g[i%2],0xc0,sizeof g[i%2]);
		for(int sa=0;sa<=n/2;sa++)
		for(int sb=0;sb<=n/2;sb++){
			int *p=&g[i%2][sa][sb];
			if(sa-1>=0)up(p,g[(i-1)%2][sa-1][sb]+a[i]);
			if(sb-1>=0)up(p,g[(i-1)%2][sa][sb-1]+b[i]);
			ans=max(ans,*p);
		}
	}
	cout<<ans<<endl;
}
void calc3(){
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d ",&a[i],&b[i],&c[i]);
		ans+=max({a[i],b[i],c[i]});
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		if(n<=30)calc();
		else if(n<=200)calc2();
		else calc3();
	}
}