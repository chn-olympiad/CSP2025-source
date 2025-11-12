#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int sz[200005],dp[200005];
int xorr[1005][1005],qzh[100005];
int s[1000005];
int xos(int a,int b){
	int la=0,lb=0;
	long long ans=0;
	while(pow(2,la)<=a){
		la++;
	}
	
	while(pow(2,lb)<=b){
		lb++;
	}
	
	int xb=0;
	memset(s,0,sizeof(s));
	for(int i=1;i<=max(la,lb);i++){
		if(a-(a/2*2)==b-(b/2*2)) s[++xb]=0;
		else s[++xb]=1;
		a/=2,b/=2;
	}
	for(int i=xb;i>=1;i--) ans=ans*2+s[i];
	return ans;
}
int xxos(int a,int b){
	int la=0,lb=0;
	long long ans=0;
	while(pow(2,la)<=a){
		la++;
	}
	
	while(pow(2,lb)<=b){
		lb++;
	}
	memset(s,0,sizeof(s));
	int xb=0;
	for(int i=1;i<=max(la,lb);i++){
		int op;
		if(b-(b/2*2)==0) op=1;
		else op=0;
		if(a-(a/2*2)==1) s[++xb]=op;
		else s[++xb]=b-(b/2*2);
		a/=2;
		b/=2;
	}
	for(int i=xb;i>=1;i--) ans=ans*2+s[i];
	return ans;
}
//int tree_find(int a,int b,int target_a,int target_b){
//	if(a<=target_a&&b<=target_b){
//		
//		return xorr[a][b];
//	}
//	if(a==b){
//		return xorr[a][b];
//	}
//	int m=a+((b-a)>>1);
//	//cout<<a<<" "<<b<<" "<<m<<"\n";
//	cout<<a<<" "<<b<<" "<<xos(tree_find(a,m,target_a,target_b),tree_find(m+1,b,target_a,target_b))<<'\n';
//	return xos(tree_find(a,m,target_a,target_b),tree_find(m+1,b,target_a,target_b));
//}
//void build(int a,int b){
//	if(a==b){
//		xorr[a][b]=sz[a];
//		return;
//	}
//	int m=a+((b-a)>>1);
//	build(a,m);
//	build(m+1,b);
//	xorr[a][b]=xos(xorr[a][m],xorr[m+1][b]);
//	return;
//}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		
		cin>>sz[i];
		qzh[i]=xos(qzh[i-1],sz[i]);
	}
	dp[1]=(sz[1]==k);
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],dp[j]+(xxos(qzh[i],qzh[j])==k));
		}
	}
	cout<<dp[n];
	return 0;
}
//记得关注释！