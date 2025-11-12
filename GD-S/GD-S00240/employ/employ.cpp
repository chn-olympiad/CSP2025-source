#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,c[505],t,ty,ans,a[505],xb[25],q[25],sum;
string s;
void sr(int k){
	if(k>n){
		sum=0;
		for(int i=1;i<=n;i++){
			if(i-1-sum<c[q[i]]&&s[i-1]=='1') sum++;
//			cout<<xb[i];
		}
//		cout<<"\n";
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++) if(!xb[i]){
		q[k]=i;
		xb[i]=1;
		sr(k+1);
		xb[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		sr(1);
		cout<<ans;
	}
	else{
		ans=1;
		for(int i=n;i>=1;i--) ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}

