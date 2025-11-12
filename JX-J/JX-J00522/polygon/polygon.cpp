#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int ans=0;
int st[5005];

long long qmi(int a,int b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=(long long)a*a%mod;
		b>>=1;
	}
	return res;
}

void dfs(int k,int sum,int K,int M,int N,int L){
	if(k>K){
		if(sum>M) ans++;
		return ;
	}for(int i=L;i<N;i++){
		if(!st[i]){
			st[i]=1;
			dfs(k+1,sum+a[i],K,M,N,i);
			st[i]=0;	
		}
	}
}

long long C(int n,int m){
	long long sum=1;
	for(int i=n;i>m;i--) sum=sum*i%mod;
	for(int i=1;i<=m-n;i++) sum=sum*qmi(i,mod-2)%mod;
	return sum;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	sort(a+1,a+1+n);
	
	if(maxx==1){
		long long sum=0;
		for(int imax=3;imax<=n;imax++)
			for(int j=3;j<=imax;j++)
				sum=(sum+C(imax-2,j-2)%mod)%mod;
		cout<<sum<<'\n';
	}
	else{
		int sum=0;
		for(int imax=3;imax<=n;imax++){
			for(int j=2;j<imax;j++){
				ans=0;
				memset(st,0,sizeof st);
				dfs(1,0,j,a[imax],imax,1);
				sum+=ans;
				//cout<<ans<<' ';
			}//cout<<'\n';
		}cout<<sum<<'\n';
	}
	return 0;
}

