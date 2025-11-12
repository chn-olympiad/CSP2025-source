#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod =  998244353;
ll n,a[5006],sa[5006];
ll f1[26][2006][106];
ll f2[5006][5006][2];
ll suma=0,maxa=0;
bool check1=1;
void work1(){
	ll ans=0;
	ll ls=n*(n-1)/2;
	for(ll i = 3;i <= n;++i){
		ls=ls*(n-i+1)/i;
		ls%=mod;
		ans+=ls;
		ans%=mod;
	}
	cout << ans << endl;
	return ;
}
void work4(){
	for(ll i = 1;i <= n;++i){
		for(ll j = 0;j <= sa[i];++j){
			for(ll kk = 1;kk <= i;++kk){
				ll k=a[kk];
				f1[i+1][j][k]=f1[i][j][k]%mod;;
				if(j+a[i+1]>2*max(a[i+1],k)&&i+1>=3){
					f1[i+1][j+a[i+1]][max(a[i+1],k)]=(f1[i][j][k]+1)%mod;
				}
			//	cout << i+1 << " " << j << " " << k <<" "<< j+a[i+1] <<" "<< max(a[i+1],k) << endl;
			//	cout << f1[i+1][j][k] << " " <<f1[i+1][j+a[i+1]][max(a[i+1],k)] << endl; 
			}
		}
	}
	ll ans=0;
	for(ll j = 0;j <= suma;++j){
		for(ll k = 0;k <=maxa;++k){
			ans+=f1[n][j][k];
			ans%=mod;
		}
	}
	cout << ans << endl;
	return ;
}
void work2(){
	if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}
	return ;
}
ll d[5006],ansdfs=0;
void DFS(ll x,ll tot,ll cnt){
//当前正在考虑第x条线段，我一共要取tot条，现在已经取了cnt条
	if(x-2>=n||cnt>tot){
		return ;
	}
	if(x==n+1&&cnt==tot){
		ll sd=0,mxd=0;
		for(ll i = 1;i <= tot;++i){
			sd+=d[i];
			mxd=max(mxd,d[i]);
		}
		if(sd>2*mxd){
//			cout << tot << endl;
//			for(ll i = 1;i <= tot;++i){
//				cout << d[i] << " ";
//			}
//			cout << endl;
			ansdfs++;
			ansdfs%=mod;
		//	cout << "KKK" << tot << endl;
		}
		return ;
	} 
//	cout << x << " " << tot << " " << cnt << endl;
//	for(ll i = 1;i <= cnt;++i){
//		cout << d[i] << " ";
//	}
//	cout << endl;
	DFS(x+1,tot,cnt);
	d[cnt+1]=a[x];
	DFS(x+1,tot,cnt+1);
	d[cnt+1]=0;
	return;
}
void work3(){
	for(ll i = 3;i <= n;++i){
		DFS(1,i,0);
	}
	cout << ansdfs%mod << endl;
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i = 1;i <= n;++i){
		cin>>a[i];
		if(a[i]!=1){
			check1=0;
		}
		suma+=a[i];
		maxa=max(maxa,a[i]);
		sa[i]=sa[i-1]+a[i];
	}
	if(check1==1){
		work1();
	}
	else if(n<=3){
		work2();
	}
	else if(n<=20){
		work3();
	}
	else if(n<=20&&suma<=2000&&maxa<=100){
		work4();
	}
	return 0;
} 
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1




*/
