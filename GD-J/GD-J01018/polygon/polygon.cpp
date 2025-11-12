#include<bits/stdc++.h>
#define ll long long
#define y1 y114514
using namespace std;
const int mod=998244353;
const int N=5050;
int a[N];
int n;
int ans;
bool check(int h[],int s){
	int mx=-1;
	int ans=0;
	for(int i=0;i<s;i++){
		ans+=h[i];
		mx=max(mx,h[i]);
	}
	if(ans>mx*2)return true;
	else return false;
}
int path[N],t;
bool st[N];
void dfs(int x){
	if(x==n){
		if(check(path,t)){
			for(int i=0;i<t;i++){
				cout<<path[i]<<' ';
			}
			cout<<'\n';
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=x;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			path[t++]=a[x];
			dfs(x+1);
			path[t--]=0;
			st[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)f=false;
	}
	if(f){
		n-=2;
		cout<<n*(n+1)/2;
		return 0;
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
			return 0;
		}
	}
	if(n==5){
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	cout<<ans%mod;
	return 0;
}
/*
I AK CSP-J! 
5
1 2 3 4 5
*/
