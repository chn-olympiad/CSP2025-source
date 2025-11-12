#include<bits/stdc++.h> 
using namespace std;
long long n,k,a[500009],m,dp[500009],c[500009];
struct node{
	long long l,r;
}b[10000009];
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long q;
		q=0;
		for(int j=i;j<=n;j++){
			q=q^a[j];
			if(q==k){
				c[i]++;
				m++;
				b[m].l=i;
				b[m].r=j;
			}
		}
	}

	int s;
	s=1;
	for(int i=1;i<=n;i++){

		for(int j=s;j<=s+c[i]-1;j++){
			dp[b[j].r]=max(dp[b[j].r],dp[b[j].l-1]+1);
		}
		dp[i]=max(dp[i],dp[i-1]);
		s=s+c[i];
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
}
