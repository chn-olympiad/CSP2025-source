#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
unsigned long long ans;
int n,a[5005],ts,bm;
void DFS(int step,int s,int m){
	if(step==n+1) return;
	ts=s+a[step];
	bm=max(a[step],m);
	if(ts>bm*2){
		ans++;
		ans%=mod;
	}
	DFS(step+1,ts,bm);
	DFS(step+1,s,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	DFS(1,0,0);
	cout<<ans;
	return 0;
}
