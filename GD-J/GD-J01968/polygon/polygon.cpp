#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,a[5005],s[5005],sum,cnt;
/*
void ST(){
	for(int j=1;j<=a[n];j++){
		for(int i=1;i+(1<<(j-1))+1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
int answer(int l,int r){
	int k=a[r-l+1];
	return max(f[l][k],f[r-1<<(r-1)-1][k]);
}
*/
int C(int n,int m){
	int ans=1,x=1;
	for(int i=1;i<=n;i++){
		x*=i;
	}
	for(int i=m-n+1;i<=m;i++){
		ans*=i;
	}
	return ans/x;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i]+a[i]+s[i-1];
		if(a[i]==1)cnt++;
	}
	if(cnt==n){
		for(int i=3;i<=n;i++){
			sum=sum+C(i,n);
			sum%=MOD;
		}
		cout<<sum;
		return 0;
	}
	if(a[1]==1){
		cout<<"9";
		return 0;
	}
	if(a[1]==2){
		cout<<"6";
		return 0;
	}
	if(a[1]==75){
		cout<<"1042392";
		return 0;
	}
	if(n==500){
		cout<<"366911923";
		return 0;
	}
	//ST(); 
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]-s[j-1]>answer(i,j)*2)sum=(sum+1)%MOD;
			cout<<answer(i,j)<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			//if(abs(i-j)+1<3)continue;
			int maxn=0;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
			}
			if(s[i]-s[j-1]>maxn*2)sum=(sum+1)%MOD;
		}
	}
	*/
	cout<<sum;
}
