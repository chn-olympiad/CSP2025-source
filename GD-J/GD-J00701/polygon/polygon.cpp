#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int a[5005],ans=0,n,b[5005];
inline void dfs(int x){
	if(x==n+1){
		int maxn=-1,z=0,s=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				maxn=max(maxn,a[i]);
				z+=a[i];
				s++;
			}
		}
		if(s>2){
			if(z>maxn*2) ans++;
		} 
	}else{
		b[x]=1;
		dfs(x+1);
		b[x]=0;
		dfs(x+1);
	}
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool is_1=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) is_1=0;
	}
	if(is_1==1){
		if(n<3) cout<<0;
		else{
			int x=(n*(n-1)*(n-2)/6)%P;
			cout<<x;
		}
	}else if(n>3&&n<=500){
		dfs(1); 
		cout<<ans;
	}
	return 0;
}
