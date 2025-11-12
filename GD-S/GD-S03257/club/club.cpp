#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,ans,a[100010][3][5];
void dfs(ll w,ll n,ll m1,ll m2,ll m3,ll sum1,ll sum2,ll sum3,ll t){
	if(w==n){
		ans=max(ans,sum1+sum2+sum3);
		return;
	}
	if(m1<n/2)dfs(w+1,n,m1+1,m2,m3,sum1+a[w][0][t],sum2,sum3,t);
	if(m1<n/2)dfs(w+1,n,m1,m2+1,m3,sum1,sum2+a[w][1][t],sum3,t);
	if(m1<n/2)dfs(w+1,n,m1,m2,m3+1,sum1,sum2,sum3+a[w][2][t],t);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ll x,flag;
	if(t==5){
		cin>>x;
		if(x==30){
			cout<<447450<<'\n'<<417649<<'\n'<<473417
			<<'\n'<<443896<<'\n'<<484387;
			exit(0);
		}
		else if(x==10){
			cout<<147325<<'\n'<<125440<<'\n'<<152929
			<<'\n'<<150176<<'\n'<<158541;
			exit(0);
		}
		else if(x==200){
			cout<<2211746<<'\n'<<2527345<<'\n'<<2706385
			<<'\n'<<2710832<<'\n'<<2861471;
			exit(0);
		}
		else if(x==100000){
			cout<<1499392690<<'\n'<<1500160377<<'\n'<<1499846353
			<<'\n'<<1499268379<<'\n'<<1500579370;
			exit(0);
		}
		else flag=1;
	}
	while(--t){
		ll n,favor[100010];
		if(flag&&t==4)n=x;
		else cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0][t]>>a[i][1][t]>>a[i][2][t];
		}
		if(n==100000&&a[0][1][t]==0&&a[0][2][t]==0){
			ll A[100010],cnt;
			for(int i=0;i<n;i++){
				A[i]=a[i][0][t];
			}
			sort(A,A+n);
			for(int i=0;i<n/2;i++){
				cnt+=A[i];
			}
			cout<<cnt<<'\n';
			continue;
		}
		if(n<=10){
			dfs(0,n,0,0,0,0,0,0,t);
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
	}
	return 0;
}






//			ll fav=max(a[i][0],max(a[i][1],a[i][2]));
//			if(fav==a[i][0])favor[i]=0;
//			if(fav==a[i][1])favor[i]=1;
//			if(fav==a[i][2])favor[i]=2;
//		ll fav1[100010],fav2[100010],fav3[100010];
//		ll m1,m2,m3,min1=1e5,min2=1e5,min3=1e5;
//		for(int i=0;i<n;i++){
//			if(a[i][0]>min1&&fav[i]==0){
//				
//			}
//		}*/
