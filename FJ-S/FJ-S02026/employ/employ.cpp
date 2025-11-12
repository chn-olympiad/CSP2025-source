#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[505];
long long b[505];
bool bb[505];
long long ans=0;
void dfs(long long x,long long s){
//	cout<<x<<' '<<s<<endl;
	if (x>n){
		if (n-s>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	if (a[x]==0){
		for(long long i=1;i<=n;i++){
			if (bb[i]==true) continue;
			bb[i]=true;
			dfs(x+1,s+1);
			bb[i]=false;
		}
		return;
	}
	for(long long i=1;i<=n;i++){
		if (bb[i]==true) continue;
		if (b[i]>s){
			bb[i]=true;
			dfs(x+1,s);
			bb[i]=false;
		}else{
			bb[i]=true;
			dfs(x+1,s+1);
			bb[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>c;
		a[i]=(c-'0');
	}
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	ans=0;
	dfs(1,0);
	cout<<(ans%998244353);
	return 0;
} 
/*
3 2
101
1 1 2

*/
