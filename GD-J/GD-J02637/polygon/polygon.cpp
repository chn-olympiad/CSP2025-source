#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n;
int a[5010],b[5010],vis[5010],c;
void dfs(int mx,int ct){
	if(ct==mx){
		int m=-1;
		long long sum=0;
		for(int i=1;i<=mx;i++){
			sum+=b[i];
			m=max(m,b[i]);
		}
		if(sum>m*2) c++;
		return;
	}
	for(int i=1;i<=n;i++){
		swap(a[i],a[1]);
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			b[ct]=a[j];
			dfs(mx,ct+1);
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	if(n<3){
		cout<<0;
	}else if(n==3){
		int cnt=0;
		if(a[1]+a[2]>a[3]) cnt++;
		cout<<cnt;
	}else if(check()){
		cout<<(n*(n-1)/2)%MOD;
	}else{
		int cnt=0;
		for(int i=4;i<=n;i++){
			memset(vis,0,sizeof vis);
			memset(b,0,sizeof b);
			dfs(i,0);
		}
		cout<<c%MOD;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
