#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
const long long mod=998244353;
int p,n,a[N],c[N];
long long dp[N][N];
bool v[N]; long long ans=0;
void dfs(int step,int maxn,int s,int Pr,int k) {
	if(step==k+1) {
		if(s>maxn*2) ans++;
		return; 
	}
	for(int i=Pr+1;i<=n;i++) {
	    if(!v[i]) v[i]=true,dfs(step+1,max(maxn,a[i]),s+a[i],i,k),v[i]=false;
	}
    return;	
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
	    cin>>a[i];
	    p=max(p,a[i]);	
	}
	sort(a+1,a+n+1);
	if(p<=1) {
		for(int i=3;i<=n;i++) dp[i][3]=(i-2)*(i-1)/2;
	    for(int i=1;i<=n;i++) {
		    for(int j=1;j<i;j++) {
			    for(int k=4;k<=n;k++) {
				    dp[i][k]=(dp[i][k]+dp[j][k-1])%mod;
				}	
			}
		}
		for(int i=1;i<=n;i++) {
		    for(int j=3;j<=n;j++) {
			    ans=(ans+dp[i][j])%mod;	
			}	
		}
		cout<<ans;
	}
	else if(n<=10) {
	    for(int i=3;i<=n;i++) {
			for(int j=1;j<=n;j++) v[j]=false;
			dfs(1,0,0,0,i);
		}	
	    cout<<ans;
	}
    return 0;	
}


//Good bye,every one.
//Maybe it's the last time I go to CSP.
//My OI 'trip' is here to the end.
//From 2021(?2020)- 2025
//I have got csp-j 1=,csp-s 1= and noip 1=.(ti yan xuan shou)
//Of course,I think maybe I will to go to noip when I'm a senior high school student.
//But maybe I will never study OI.
//I am not good at English (liu han huang dou)
//It has been 0.5 yearts since I last study OI during Sheng Xuan.
//Luogu uid:623291,huan ying guan zhu wo!
//And you can get further information in my blog.
//There are my csp, noip and Shengxuan youji.
//It is a record of my personal expriences.
//Wo yao shang CSP-J 2025 AH mi huo xing wei da jiang!(mu qian hai mei shang guo)
