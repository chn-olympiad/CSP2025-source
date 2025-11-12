#include<bits/stdc++.h>
#define int long long
using namespace std;
const signed N=5e5+5;
int n,k;
int a[N];
int s[N];
int dp[N];
pair<int,int> p[N];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int in=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=s[j]^s[i-1];
			if(x==k){
				p[in++]={i,j};
			}
		}
	}
	in--;
	int maxn=0;
	sort(p+1,p+1+in,cmp);
	for(int i=1;i<=in;i++){
		int sum=1;
		pair<int,int> cur=p[i];
		for(int j=i;j<=in;j++){
			if(p[j].first>=cur.second){
				sum++;
				cur=p[j];
			}
		}
		dp[i]=sum;
	}
	for(int i=1;i<=in;i++){
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
