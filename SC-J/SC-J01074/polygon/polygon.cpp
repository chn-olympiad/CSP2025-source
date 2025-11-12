#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],sum[5005],vis[5005];
int ans=0;
set<vector<int> >s;
vector<int>v;
void dfs(int sum2,int step,int x){
	if(step<=-1){
		if(sum2>(x<<1)){
//			for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
//			cout<<'\n';
//			s.insert(v);
			ans++;
			ans%=mod;
		}
		return;
	}
	if(sum2+sum[step]<=(x<<1))return;
	v.push_back(a[step]);
	dfs(sum2+a[step],step-1,x);
	v.pop_back();
	dfs(sum2,step-1,x);
	return;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool flag=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vis[a[i]]++;
		if(a[i]!=1)flag=false;
	}
	if(flag){
		long long mul=1;
		for(int i=1;i<=n;i++){
			mul*=2;
			mul%=mod;
		}
		mul+=mod;
		mul-=(n-1)*n/2;
		mul-=n;
		mul--;
		mul%=mod;
		cout<<mul;
		return 0;
	}
	for(int i=0;i<n;i++)sum[i]=(i-1<0?0:sum[i-1])+a[i];
	sort(a,a+n);
	for(int i=2;i<n;i++){
		dfs(a[i],i-1,a[i]);
	}
	cout<<ans;
	return 0;
}
