#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;

int n,ans;
int a[5005];

int f(int i,int m,int mxa,int sum){
	if(i>n){
		if(m>=3&&sum>(mxa<<1)){
//			cout<<1;
			return 1;
		}
		else{
//			cout<<0;
			return 0;
		}
	}
	int r;
	if(i==n&&m<2) return 0;
	if(i==n-1&&m<2){
		if(m<1) return 0;
		else r=f(i+1,m+1,max(mxa,a[i]),sum+a[i]);
	}
	else if(i==n-2&&(!m)) r=f(i+1,m+1,max(mxa,a[i]),sum+a[i]);
	else r=f(i+1,m,mxa,sum)+f(i+1,m+1,max(mxa,a[i]),sum+a[i]);
//	cout<<"f("<<i<<','<<m<<','<<mxa<<','<<sum<<")="<<r<<endl;
//	if(m>=3&&sum>(mxa<<1)) r++;
//	cout<<'+';
	r%=M;
//	cout<<"-><<r;
	return r;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++) for(int j=i-2;j>0;j--){
//		if(sum[i]-sum[j-1]>(a[i]<<1)) ans=(ans+1)%M;
//	}
	cout<<f(1,0,0,0);
}
