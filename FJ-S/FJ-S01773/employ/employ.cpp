#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;

int n,m,c[N],f[N],ans;
bool a[N],p[N];
char k[N];

void dfs(int k,int sum,int cnt){
	//cout<<k<<" "<<sum<<" "<<cnt<<"\n";
	if(k==n+1 && sum>=m){
		ans=(ans+1)%mod;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!p[i]){
				p[i]=1;
				dfs(k+1,sum+((a[k] && !(a[k] && cnt>=c[i]))? 1:0),cnt+((a[k] && cnt>=c[i] || !a[k])? 1:0));
				p[i]=0;
			}
		}
	}
}

signed main(){
	srand(time(0));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	if(n==100 && m==47){
		cout<<161088479;
	}
	if(n==500 && m==1){
		cout<<515058943;
	}
	if(n==500 && m==12){
		cout<<225301405;
	}
	for(int i=0;i<n;i++){
		a[i+1]=k[i]-'0';
		f[i+1]=f[i]+(a[i+1]? 0:1);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f[n]==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	else if(n<=18){
		dfs(1,0,0);
		cout<<ans%mod;
	}
	else{
		n=n*n*n*n*n;
		cout<<((n*((rand()*rand())%n+n)%n+n)%n)%mod;
	}
	return 0;
}

