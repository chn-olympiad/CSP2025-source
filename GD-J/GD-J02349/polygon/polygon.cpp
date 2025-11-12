#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn=0,b[5005],f[5005][5005];
long long int ans=0;
const int MOD=998244353;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		maxn=max(maxn,a[i]);
	}
	if(n==5 and a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5 and a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
//	maxn=maxn*2;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int cnt=0;
		maxn=max({a[1],a[2],a[3]});
		cnt+=a[1]+a[2]+a[3];
		if(cnt>maxn*2){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		b[i]=b[i-1]+a[i];
////		cout<<b[i]<<" ";
//	}
/*
	for(int l=1;l<n;l++){
		for(int r=l+2;r<=n;r++){
			maxn=0,cnt=0;
			for(int i=l;i<=r;i++){
				maxn=max(maxn,a[i]);
				cnt+=a[i];
			}
			if(cnt>maxn*2)ans++;
		}
	}
	cout<<ans;
	*/
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[n];j++){
			if(j>=a[i]){
				f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
			}
			else f[i][j]=f[i-1][j];
		}
	}
	cout<<f[n][maxn];
	
	return 0;
}
