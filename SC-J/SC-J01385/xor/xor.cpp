#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10; 
int n,k;

int dp[maxn];
int num[maxn];
int ans;
int xh;
struct node{
	int first,second;
	bool operator<(const node& tmp)const{
		return first<tmp.first;
	}
	bool operator<(const int& tmp)const{
		return first<tmp;
	}
	bool operator==(const node& tmp)const{
		return first==tmp.first;
	}
};
node M[maxn];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int x=0;
	for(int i=1;i<=n;i++){
		x=x^num[i];
		M[i]={x,-1};
	}
	sort(M+1,M+1+n);
	int len=unique(M+1,M+1+n)-M-1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int u=num[i];
		int f=k^u^xh;
	
		int q=lower_bound(M+1,M+len+1,f)-M;
		int zhi=M[q].second;
		if(u==k){
			dp[i]=max(dp[i],dp[i-1]+1);
		}else if(zhi!=-1){
			dp[i]=max(dp[i],dp[M[q].second]+1);
		}
		int New=xh^u;
		q=lower_bound(M+1,M+len+1,New)-M;
		M[q].second=max(i,M[q].second);
		xh=New;
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	
	return 0;
}