#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define M 2000005
#define mod 998244353 
using namespace std;
ll n,a[N],num[M],tot,ans,f[M];
struct node{
	ll a,b,c;
}s[N];
bool cmp(ll a,ll b){
	return a>b;
}
void check(){
	for(int i=1;i<=15;i++){
		cout<<i<<" "<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<endl;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(f,-63,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);tot=1;
	for(int i=1;i<n;i++){
		sort(num+1,num+tot+1,cmp);
		for(int j=tot;j>=1;j--){
			ll wa=s[num[j]].a,wb=s[num[j]].b,wc=s[num[j]].c;
//			cout<<num[j]<<" "<<wa<<" "<<wb<<" "<<wc<<endl;
			s[num[j]+a[i]].c+=s[num[j]].c;
			s[num[j]+a[i]].c+=s[num[j]].b;
			s[num[j]+a[i]].b+=s[num[j]].a;
			if(num[j]+a[i]>a[i+1]) ans=(ans+s[num[j]+a[i]].b+s[num[j]+a[i]].c)%mod;
			if(f[num[j]+a[i]]<0) tot++,num[tot]=num[j]+a[i],f[num[j]+a[i]]=1;
		}
		s[a[i]].a++;
//		check();
//		cout<<ans<<endl;
	}
	printf("%lld",ans);
	return 0;;
}
/*
5 0
1 3 2 4 4
*/
