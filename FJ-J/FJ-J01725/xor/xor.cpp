#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[501010];
int vis[55],fil[55];
int dp[501010],x[501010][22];
unordered_map<string,int> mu;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int j=1;
		while(a[i]){
			if(a[i]&1) x[i][j]=1;
			a[i]=a[i]>>1;
			j++;
		}
	}
	int cs=1;
	while(k){
		if(k&1) fil[cs]=1;
		k=k>>1;
		cs++;
	}
	for(int w=1;w<=20;w++){
		for(int i=1;i<=n;i++){
			x[i][w]+=x[i-1][w];
			x[i][w]%=2;
		}
	}
	string s,r;
	for(int w=1;w<=20;w++){
		s+='0';
	}
	mu[s]=1;
	for(int i=1;i<=n;i++){
		s="";r="";
		for(int w=1;w<=20;w++){
			r+=((x[i][w]+fil[w])%2+'0');
			s+=(x[i][w]+'0');
		}
		//cout<<s<<endl<<r<<endl;
		dp[i]=dp[i-1];	
		if(mu[r]){
			dp[i]=max(dp[i],dp[mu[r]-1]+1);	
		//	cout<<i<<' '<<mu[r]-1<<endl;
		}
		mu[s]=i+1;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
}
/*
4 2
2 1 0 3
*/
