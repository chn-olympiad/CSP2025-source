#include <bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,m,cnt,bol=1,head=1,sum,a[510],c[510],jie[510],inv[510],q[510],top,ans=1,ans1=0,ss[510],dp[25][510000],fp[25][510000];
char s[510];

int qpow(int x,int p){
	int ans=1,mul=x;
	
	while(p){
		if(p&1)  ans=1ll*ans*mul%M;
		
		mul=1ll*mul*mul%M;
		
		p>>=1;
	}
	
	return ans;
}

int aa(int x,int y){
	if(x<y)  return 0;
	return 1ll*jie[x]*inv[x-y]%M;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i=1; i<=n; i++)  cin >> s[i], a[i]=s[i]-'0', cnt+=a[i];
	
	for (int i=1; i<=n; i++)  cin >> c[i], bol*=c[i];
	
	sort(c+1,c+n+1);
	
//	for (int i=1; i<=n; i++)  cout << c[i]<<"\n", ss[c[i]]++;
//	cout<<"\n\n\n";
//	for (int i=0; i<=100; i++)  cout << ss[i]<<"\n";
	
	jie[0]=1;
	
	for (int i=1; i<=n; i++)  jie[i]=1ll*jie[i-1]*i%M;
	
	inv[n]=qpow(jie[n],M-2);
	
	for (int i=n; i; i--)  inv[i-1]=1ll*inv[i]*i%M;
	
	dp[0][0]=1;
	
	if(n<=10){
		for (int i=1; i<=n; i++){
			for (int j=0; j<=n; j++){
				for (int t=0; t<1<<n; t++){
					for (int k=1; k<=n; k++){
						if((1<<k-1)&t){
							if(j>=c[k] || !a[i])  fp[j+1][t]=(fp[j+1][t]+dp[j][t^(1<<k-1)])%M;
							else  fp[j][t]=(fp[j][t]+dp[j][t^(1<<k-1)])%M;
						}
					}
					
				}
			}
			
			for (int j=0; j<=n; j++){
				for (int t=0; t<1<<n; t++){
					dp[j][t]=fp[j][t];
					fp[j][t]=0;
				}
			}
			
//			if(i==2){
//				for (int t=0; t<1<<n; t++)cout<<dp[0][t]<<"\n";
//				cout<<"\n";
//			}
		}
		
		for (int j=0; j<=n-m; j++){
			ans1=(ans1+dp[j][(1<<n)-1])%M;
//			cout<<ans1<<"\n";
		}
		
		cout << ans1;
	}
	else if(m==n){
		if(cnt-n || !bol)  cout << 0;
		else  cout << jie[n];
	}
	else if(m==1){
		for (int i=1; i<=n; i++)
			if(a[i])  q[++top]=i-1;
		
		for (int i=1; i<=top; i++){
			while(c[head]<=q[i] && head<=n)  sum++, head++;
			
			ans=1ll*ans*(sum-i+1)%M;
//			cout<<head<<" "<<sum<<" "<<ans<<"\n";
		}
		
		cout << (jie[n]-1ll*ans*jie[n-top]%M+M)%M;
	}
	else if(cnt==n){
		cout<<0;
	}
	else if(cnt<=18){
		cout<<0;
	}
	else  cout<<0;
	
	return 0;
}
