#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e3+8;
int n,k,cnt=0,sum=0,flag=0;
int a[N],vis[N];
map<pair<int,int>,int> dp;
struct node{
	int len,l,r;
}ans[N];
inline bool cmp(node x,node y){
	return x.len<y.len;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[{i,i}]=a[i];
		if(a[i]==k){
			ans[++cnt]={0,i,i};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[{i,j}]=dp[{i,j-1}]^a[j];
			if(dp[{i,j}]==k){
				ans[++cnt]={j-i,i,j};
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int l=ans[i].l,r=ans[i].r;
		for(int j=l;j<=r;j++){
			if(vis[j]){
				flag=1;
				break;
			}
			vis[j]=1;
		}
		if(flag){
			break;
		}
		sum++;
	}
	cout<<sum;
	return 0;
}
