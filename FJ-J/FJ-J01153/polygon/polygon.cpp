#include <bits/stdc++.h>
using namespace std;
long long a,b[5001],ans,maxn,v[5001],c[5001],vis[5001];
const int M=998244353;
bool check(int n){
	long long sum=0,m=0;
	for(int i=1;i<=n;i++){
		if(c[i]<c[i-1]){
			return 0;
		}
		m=max(m,c[i]);
		sum+=c[i];
	}
	if(sum>2*m){
		return 1;
	}
	return 0;
}
void dfs(int x,int n){
	if(x>n){
		if(check(n)){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=a;i++){
		if(vis[i]==0){
			vis[i]=1;
			c[x]=b[i];
			dfs(x+1,n);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		v[b[i]]++;
		maxn=max(maxn,b[i]);
	}
	if(maxn==1){
		long long s=1;
		for(int i=1;i<=a;i++){
			s*=i;
			s%=M;
		}
		for(int f=3;f<=a;f++){
			long long x=1,y=1;
			for(int i=1;i<=f;i++){
				x*=i;
				x%=M;
			}
			for(int i=1;i<=a-f;i++){
				y*=i;
				y%=M;
			}
			ans=ans+(s/x/y);
			ans%=M;
		}
		cout<<ans;
		return 0;
	}
	sort(b+1,b+1+a);
	for(int k=3;k<=a;k++){
		dfs(1,k);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
