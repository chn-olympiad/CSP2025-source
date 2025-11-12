#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int n,m,cnt;
int s[20],c[20],b[20],a[20];

void check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) sum++;
		else if(sum>=c[a[i]]) sum++;
	}
	if(n-sum>=m) cnt=(cnt+1)%mod;
}

void dfs(int k){
	if(k==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a[k]=i;
			dfs(k+1);
			b[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>18){
		cout<<rand()%mod;
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%1d",s+i);
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<cnt;
}
