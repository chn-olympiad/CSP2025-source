#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const ll mod=998244353;
ll n,a[5005],ans;
void dfs(int x,int sum,int k){
	sum+=a[x];
	if(sum>k)ans++;
	for(int i=1;i<x;i++){
		dfs(i,sum,k);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,a[i]*2);
	}
	cout<<ans;
}
