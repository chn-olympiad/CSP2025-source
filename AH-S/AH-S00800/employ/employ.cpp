#include<bits/stdc++.h>
using namespace std;
int const mod=998244353;
int n,m,aa[505],c[505],sum[505],a[505];
int ans[505];
long long ans2=0;
string s;
void slove(int x,int lim){
	if(lim==0){
		int ans1=1;
		for(int i=n;i>=1;i--){
			int ss=0;
			for(int j=a[i]+1;j<=n;j++) ss+=sum[j];
			ans[i]=ss-n+i;
		}
		for(int i=1;i<=n;i++){
			if(ans[i]!=0) ans1=(ans1*ans[i]*1ll)%mod;
		}
		ans2=(ans1+ans2)%mod;
		return;
	}
	for(int i=x;i>=1;i--){
		if(s[i-1]=='1'){
			for(int j=i+1;j<=n;j++) a[j]++;
			slove(i,lim-1);
			for(int j=i+1;j<=n;j++) a[j]--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	a[1]=0;
	for(int i=2;i<=n;i++) aa[i]=aa[i-1]+(s[i-2]=='0');
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	if(aa[n]==0){
		int ss1=0,ans3=1;
		for(int i=1;i<=n;i++) {
			if(c[i]==0) ss1++; 
		}
		for(int i=1;i<=n-ss1;i++) ans3=(ans3*i)%mod;
		for(int i=1;i<=ss1;i++) ans3=(ans3*i)%mod;
		cout<<ans3%mod<<endl;
		return 0;  
	}
	for(int i=1;i<=n;i++) sum[c[i]]++;
	int op=n-aa[n]-m+1;
	while(op>0){
		for(int i=1;i<=n;i++) a[i]=aa[i];
		slove(n-1,op-1);
		op--;
	}
	cout<<ans2<<endl;
}
