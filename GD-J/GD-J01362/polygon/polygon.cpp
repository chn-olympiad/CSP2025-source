#include<bits/stdc++.h>
using namespace std;
const int N=5000+23,mod=998244353;
//过程可能爆long long
int a[N],n,dp[N],mx=0,c[N][N];//dp
vector<int> x;
long long ans=0;
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		int xx=max({a[1],a[2],a[3]})*2;
		int x1=a[1]+a[2]+a[3];
		if(xx<x1)
		{
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	if(mx==1){
		c[0][0]=1;
		c[1][0]=1;
		c[1][1]=1;
		for(int i=1;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++)
			{
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				c[i][j]%=mod;
//				cout << i << ' '<< j << ' ' << c[i][j] << "\n"; 
			}
		}
		
		for(int i=3;i<=n;i++){
			for(int j=3;j<=i;j++){
				ans+=c[i][j];
				ans%=mod;
			}
		}
		cout << ans%mod;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){//1~i
		int da=a[i];
		for(int j=0;j<int(x.size());j++){
			int now=x[j];
			x.push_back(now+a[i]);
		}
		x.push_back(a[i]);
		if(x[(int)(x.size())-1]>=da){
			int fi=lower_bound(x.begin(),x.end(),da)-x.begin();
			cout << fi;
			ans+=int(x.size())-fi-1;
		}
	}
	cout << ans; 
	return 0;
} 
