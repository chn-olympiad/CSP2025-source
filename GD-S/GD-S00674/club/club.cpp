#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+10,M=205;
int n;
ll su,f[M][M][M],spc;
bool suab;
struct cs{
	ll a,b,c;
}a[N],sp[N];
ll mx[N];
int c0,c1,c2,cnt0,cnt1,cnt2;
bool cmpABC(cs x,cs y){
	return c0*x.a+c1*x.b+c2*x.c>c0*y.a+c1*y.b+c2*y.c;
} 
ll dospc1(){
	c0=0,c1=+1,c2=-1,su=0;
	sort(sp+1,sp+spc+1,cmpABC);
	for(int i=1;i<=spc;i++) 
		su+=(i<=n/2?sp[i].b:sp[i].c);	
	return su;
}
ll dospc2(){
	c0=+1,c1=0,c2=-1,su=0;
	sort(sp+1,sp+spc+1,cmpABC);
	for(int i=1;i<=spc;i++)
		su+=(i<=n/2?sp[i].a:sp[i].c);
	return su;
}
ll dospc3(){
	c0=+1,c1=-1,c2=0,su=0;
	sort(sp+1,sp+spc+1,cmpABC);
	for(int i=1;i<=spc;i++)
		su+=(i<=n/2?sp[i].a:sp[i].b);
	return su;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		suab=1;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c,
			mx[i]=max(a[i].a,max(a[i].b,a[i].c)), 
			suab&=(a[i].c==0);
		if(n<=200){
			for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)
				f[i][j][k]=0;
			for(int p=1;p<=n;p++)for(int i=0;i<=p;i++)for(int j=0;i+j<=p;j++){
				int k=p-i-j;
				if(i)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[p].a);
				if(j)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[p].b);
				if(k)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[p].c);
			}
			ll ans=0;
			for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)for(int k=0;k<=n/2;k++)
				ans=max(ans,f[i][j][k]);
			cout<<ans<<"\n";
		}else if(suab){
			c0=-1,c1=+1,c2=-1;
			sort(a+1,a+n+1,cmpABC);
			su=0;
			for(int i=1;i<=n;i++)
				su+=(i<=n/2?a[i].b:a[i].a);
			cout<<su<<"\n";
		}else{
			ll ans=0;
			cnt0=cnt1=cnt2=0;
			for(int i=1;i<=n;i++){
				if(a[i].a==mx[i]) cnt0++;
				if(a[i].b==mx[i]) cnt1++;
				if(a[i].c==mx[i]) cnt2++;
			}
			spc=0;
			if(cnt0<=n/2&&cnt1<=n/2&&cnt2<=n/2){
				for(int i=1;i<=n;i++)
					ans+=mx[i];
				cout<<ans<<"\n";
			}else cout<<ans<<"\n";
		}
	}
	return 0;
}
