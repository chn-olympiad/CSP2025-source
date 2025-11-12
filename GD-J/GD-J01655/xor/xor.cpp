#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long n,k;
long long a[maxn];
struct u{
	int num;
	int xu;
}b[maxn];
bool cmp(u x,u y){
	if(x.num<y.num)return 1;
	if(y.num==x.num&&x.xu<y.xu)return 1;
	return 0;
}
int dp[maxn];
int find(int nu,int x){
	int l=0,r=n;
	int re=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid].num>nu||(b[mid].xu>x&&b[mid].num==nu)){
			r=mid-1;
		}else if(b[mid].xu<x&&b[mid].num==nu){
			l=mid+1;
			re=b[mid].xu;
		}else{
			l=mid+1;
		}
	}
	return re;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0].num=k;
	b[0].xu=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
		b[i].num=a[i]^k;
		b[i].xu=i;
	}
	sort(b,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		int u=find(a[i],i);
		if(u==-1)dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[u]+1);
	}
	cout<<dp[n];
	return 0;
} 
