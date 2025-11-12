#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[100005];
char s[100005];
int c[100005];
long long dp[505][505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool sf=1;
	for(int i=1;i<=n;i++){
		a[i]=i;
		cin>>s[i];
		if(s[i]=='0')sf=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=0;
	if(n<=10){
		do{
			int nx=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(nx>=c[a[i]]){
					nx++;
					continue;
				}
				else if(s[i]=='0'){
					nx++;
				}
				else{
					cnt++;
				}
			}
			if(cnt>=m)ans++;
			ans%=mod;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans%mod;
	}
	else if(n==m){
		bool fl=1;
		long long lx=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0)fl=0;
			lx*=i;
			lx%=mod;
		}
		cout<<lx*fl%mod;
	}
	else if(sf){
		dp[0][0]=1;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				int ls=upper_bound(c+1,c+n+1,j)-c-1;
				dp[i][j]=dp[i-1][j-1]*(ls-j-1)+dp[i-1][j]*(n-ls);
				dp[i][j]%=mod;
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++){
			ans+=dp[n][i];
			ans%=mod;
		}
		cout<<ans%mod;
	}
	else if(m==1){
		c[n+1]=INT_MAX;
		sort(c+1,c+n+1);
		long long ans=1,fq=0,lx=1,np=1,cnt=0;
		for(int i=1;i<=n;i++){
			//cout<<c[i]<<" "<<i<<"\n";
			lx*=i;
			lx%=mod;
			while(c[np]<=fq){
				cnt++;
				np++;
			}
			if(s[i]=='1')ans*=cnt,cnt--;
			ans%=mod;
			fq++;
			cnt--;
			//if(cnt==0)cout<<i<<endl;
		}
		cout<<(lx+mod-ans)%mod;
	}
	return 0;
}
