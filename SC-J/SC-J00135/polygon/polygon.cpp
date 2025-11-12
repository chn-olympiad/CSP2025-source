#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100010],ans,am;
#define M 998244353
void dfs(int pos,int mx,int cnt,int use){
	if(pos>n){
		if(mx*2<cnt&&use>=3){
			ans=(ans+1)%M;
		}
		return;
	}
	dfs(pos+1,max(mx,a[pos]),cnt+a[pos],use+1);
	dfs(pos+1,mx,cnt,use);
	return;
}
int c(int A,int B){
	ll t=1;
	if(B>=(A/2.0))B=A-B;
	for(int i=1;i<=B;++i)t=t*(A-i+1)%M;
	for(int i=1;i<=B;++i)t=(t/(B-i+1)%M)%M;
	return t%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		am=max(am,a[i]);
	}
	if(am>1)dfs(1,0,0,0);
	else {
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%M;
		}
	}
	cout<<ans%M<<endl;
	return 0;
}