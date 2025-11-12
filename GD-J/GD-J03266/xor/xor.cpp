#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int n,k;
const int N=5e5+5;
bool vis[N];
ll a[N];
ll pre[N];
ll f(ll x,ll y){
	ll num=0;
	ll s=0;
	while(!(x==0&&y==0)){
		if(x%2!=y%2){
			num+=pow(2,s);
		}
		s++;
		x/=2;
		y/=2;
	}
	return num;
}
bool fn(int x,int y){
	for(int i=x;i<y;i++){
		if(f(pre[i],pre[y])==k)return 1;
	}
	return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[0]=0;
	int x=0;
	for(int i=1;i<=n;i++){
		pre[i]=f(a[i],pre[i-1]);
		if(pre[i]==k||a[i]==k||fn(x,i)){
			cnt++;
			pre[i]=0;
			x=i+1;
		}	

	}
//	int cntn=0;
//	for(int i=n;i>=1;i--){
//		pre[i]=f(a[i],pre[i+1]);
//		if(pre[i]==k||a[i]==k){
//			cntn++;
//			pre[i]=0;
//		}			
//
//	}
//	for(int i=1;i<=n;i++){
//		cout<<pre[i]<<" ";
//	}
	cout<<cnt;
	return 0;
}
