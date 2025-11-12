#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
struct node{
	int l,r;
};
bool cmp(node x,node y){
	if(x.r==y.r)return x.l<y.l;
	else return x.r<y.r;
}
vector<node> v;
int n,k,a[N],res[N],dp[N],ans=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res[i]=res[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=res[j]^res[i-1];
			if(sum==k){
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[j].l>v[i].r)dp[j]=max(dp[i]+1,dp[j]);
		}
	}
	cout<<dp[v.size()-1]+1;
	return 0;
}
