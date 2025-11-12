#include <bits/stdc++.h>
using namespace std;
const int N=5005;
const int p=998244353;
int n;
int a[N];
long long jc[N];
long long ny[N];
int cnt=0;
void dfs(int p,int s,int ma){
	if(p==n+1&&s>ma*2){
		cnt++;
		return;
	}
	if(p==n+1){
		return;
	}
	dfs(p+1,s+a[p],max(ma,a[p]));
	dfs(p+1,s,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool b=true;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=false;
		}
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	} 
	if(b){
		jc[0]=ny[0]=jc[1]=ny[1]=1;
		for(int i=2;i<=n;i++){
			jc[i]=1ll*jc[i-1]*i%p;
			ny[i]=p-1ll*p/i*ny[p%i]%p;
		}
		for(int i=2;i<=n;i++){
			ny[i]=1ll*ny[i-1]*ny[i]%p;
		}
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+(1ll*jc[n]*ny[i]%p*ny[n-i]%p))%p;
		}
		cout<<ans<<endl;
	}else{
		dfs(1,0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
