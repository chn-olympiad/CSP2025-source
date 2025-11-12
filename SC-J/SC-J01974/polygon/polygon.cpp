#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],p[N],rp[N],d[N],rd[N];
int mpow(int n,int k){
	int ans=1;
	while(k){
		if(k&1)ans=(ans*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ans;
}
void pre(){
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=(p[i-1]*i)%mod;
	rp[N-1]=mpow(p[N-1],mod-2);
	for(int i=N-2;i>=0;i--)rp[i]=(rp[i+1]*(i+1))%mod;
}
int C(int n,int m){
	return p[n]*rp[n-m]%mod*rp[m]%mod;
}
bool cmp(int a,int b){
	return a>b;
}
inline int ct(vector<int>&v){
	int ans=0;
	for(int eg:v)if(eg>0)++ans;
	return ans;
}
void dfs(int l,int r,int k,int sum,int mx,int& t,vector<int>v){//[l,r]
	cout<<sum<<"\n";
	if(sum>mx){t+=C(ct(v),k);cout<<k<<" "<<t<<"\n";return;}
	if(k==0){return;}
	for(int i=0;i<(int)v.size();i++){
		if(v[i]==0)continue;
		int sw=v[i];v[i]=0;
		cout<<v[i]<<" ";
		dfs(l,r,k-1,sum+sw,mx,t,v);
		v[i]=sw;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fre("polygon");
	pre();
	cin>>n;
	bool fl=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(n<3){
		cout<<"0\n";
		return 0;
	}
	if(fl){
		int ans=0;
		for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
		cout<<ans<<"\n";
		return 0;
	}
	if(n<=20){
		int ans=0,mx=0,sum=0,cnt=0;
		for(int i=0;i<(1<<n);i++){
			mx=0,sum=0,cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)sum+=a[j],mx=max(mx,a[j]),cnt++;
			}
			if(cnt>=3&&sum-mx>mx){
				++ans;
				if(ans>mod)ans%=mod;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	int ans=0;
	sort(a,a+n,cmp);
	for(int i=n-1;i>=0;i--)rd[i]=rd[i+1]+a[i];
	for(int i=0;i<n;i++)d[i]=d[max(0LL,i-1)]+a[i];
	for(int i=0;i<n;i++){
		int l=i+1,r=n-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(d[mid]-d[i]<=a[i])l=mid+1;
			else r=mid-1;
		}
		int nl=l-i;l=i+1,r=n-1;
		int mx=0,sum=0,cnt=0;
		for(int mk=0;mk<(1<<(r-l+1));mk++){
			int sum=0,cnt=0;
			for(int k=0;k<(r-l+1);k++){
				if((mk>>k)&1)sum+=a[k+l],cnt++;
			}
			if(cnt>=nl&&(sum>a[i])){
				++ans;
				if(ans>mod)ans%=mod;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}