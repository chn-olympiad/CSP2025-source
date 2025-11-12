#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c[510],dp[510][510],qz[510],t[510],qzt[510],mod=998244353,ans;
char s[1010];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') qz[i]=qz[i-1];
		else if(s[i]=='1') qz[i]=qz[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		t[c[i]]++;
	}
	for(int i=1;i<=n;i++){
		qzt[i]=qzt[i-1]+t[i];
	}
	//if(m==1){
		dp[0][0]=1;
		ll jd=n-qz[n],jt=1,jo=1;
		for(int i=1;i<=jd;i++){
			jt*=2;
			jt%=mod;
		}
		for(int i=1;i<=n;i++){
			dp[i][0]=1;
			dp[0][i]=1;
		}
		for(int i=1;i<=n;i++){//天数 
			if(s[i]=='0'){
				for(int j=1;j<=n;j++){//人数 
					dp[i][j]=dp[i][j-1]*(max(0LL,(qz[i]-qz[c[j]]))+1);//+dp[i-1][j-1]*max(0LL,(qz[i]-qz[c[j]])+1);
				}
			}
			else{
				for(int j=1;j<=n;j++){//人数 
					dp[i][j]=dp[i][j-1]*(max(0LL,(qz[i]-qz[c[j]]))+1);//+dp[i-1][j-1]*max(0LL,(qz[i]-qz[c[j]])+1);
					dp[i][j]%=mod;
				}
			}
			/*for(int j=1;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}	
			cout<<endl;
			*/
		}
		ans=dp[n][n];
		ans%=mod;
		for(int i=1;i<=n;i++){
			jo*=i;
			jo%=mod;
		}
		ans=jo-ans;
		ans+=mod;
		ans%=mod;
		cout<<ans<<endl;
	//}
	return 0;
} 
/*
5 1
10100
0 1 2 2 2
*/
