#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long ans;
bool c[5005];
const long long mod=998244353;
void dfs(int x,int k){
	if(k>=3){
		int s=0,ss=0;
		for(int i=1;i<k;i++){
			ss+=b[i];
			s=max(s,b[i]);
		}
		if(s*2<ss) ans++;
	}
	for(int i=x;i<=n;i++){
		if(!c[i]){
			c[i]=1;
			b[k]=a[i];
			dfs(i+1,k+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
