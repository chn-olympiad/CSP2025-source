#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mo=998244353;
int n,a[5001],mp[5001],mx,an,tp;
int su,f[500001],c[5001][5001];
int pw(int a,int b){
	int re=1;
	while(b){
		if(b&1)re=re*a%mo;
		a=a*a%mo,b>>=1;
	}
	return re;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],mp[a[i]]++;
		mx=max(mx,a[i]);
	}
	for(int i=0;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	f[0]=1;
	for(int i=1;i<=mx;i++){
		if(!mp[i])continue;
		if(mp[i]>=2){
			int c2=mp[i]*(mp[i]-1)/2%mo;
			int c3=((pw(2,mp[i])-1-mp[i]-c2)%mo+mo)%mo;
			if(mp[i]>=3)an=(an+c3*pw(2,su)%mo)%mo;
			an=(an+c2*(pw(2,su)-1)%mo)%mo;
		}
		int no=0;
		for(int j=i+1;j<=mx;j++)no=(no+f[j])%mo;
		no=(no+tp)%mo;
		an=(an+mp[i]*no%mo)%mo;
		tp=(tp+tp*(pw(2,mp[i])-1)%mo)%mo;
		for(int k=mx;k>=0;k--){
			for(int j=1;j<=mp[i];j++){
				if(k+j*i>n*mx)continue;
				if(k+j*i>mx)tp=(tp+f[k]*c[mp[i]][j]%mo)%mo;
				else f[k+j*i]=(f[k+j*i]+f[k]*c[mp[i]][j]%mo)%mo;
			}
		}
		su=(su+mp[i])%mo;
	}
	cout<<an;
	return 0;
}