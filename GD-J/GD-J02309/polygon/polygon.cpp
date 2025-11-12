#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
long long n,a[N],b[N],ans;
bool st[N];
void dfs(long long u,long long s){
	if(u>n+1) return;
	if(u>3&&s>a[b[u-1]]*2){
		ans=(ans+1)%mod;
	}
	for(int i=b[u-1]+1;i<=n;i++){
		if(!st[i]){
			b[u]=i;
			st[u]=true;
			s+=a[i];
			dfs(u+1,s);
			b[u]=0;
			st[u]=false;
			s-=a[i];
		}
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<ans%mod<<endl;
	return 0;
}
/*
2 2 3 8 10
1 2 3 4 5
*/

