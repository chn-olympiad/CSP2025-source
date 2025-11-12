#include<bits/stdc++.h>
using namespace std;
int n,m,ans,i,j,c;
int b[10009];
int f[10009],dp[10009];
int s[10009];
int check(int x,int y){
	sort(b+x+1,b+y+1);
	if(s[y]-s[x-1]>=b[y]*2)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polrgon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>b[i];
	}
	f[0]=1;
	f[1]=1;
	dp[0]=1;
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++){
		s[i]=s[i-1]+b[i];
		//<<s[i]<<" ";
	}
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		for(j=i;j<=n;j++){
			cout<<check(i,j)<<endl;
			if(check(i,j))dp[j]=max(dp[j],f[j-1])%998244353+1;
			f[j]=max(dp[j],f[j-1])%998244353;
		}
	}

	cout<<f[n]%998244353;
	return 0;
}
/*
in:
5
1 2 3 4 5

out:
9
*/
