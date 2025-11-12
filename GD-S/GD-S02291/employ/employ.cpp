#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,aaa[501],ans=0;
char c[501];
int pd(int a[]){
	int b=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='0')b++;
		else if(aaa[a[i]]>b)cnt++;
	}
	return cnt;
}
void dfs(int c,bool f[],int a[]){
	if(c==n){
		if(pd(a)>=m)ans++;
	}
	bool f1[501];
	for(int i=1;i<=n;i++){
		if(f[i])f1[i]=true;
		else f1[i]=false;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		a[c+1]=i;
		f1[i]=true;
		dfs(c+1,f1,a);
		f1[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	bool f1=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0')f1=false;
	}
	for(int i=1;i<=n;i++)cin>>aaa[i];
	if(f1){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	bool f[501];
	int a[501];
	memset(f,false,sizeof(f));
	dfs(0,f,a);
	cout<<ans;
}
