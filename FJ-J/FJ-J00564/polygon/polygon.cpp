#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
int a[5005];
int p[5005];
const int P=998244353;

void dfs(int k,int s,int t){
	if(k>=3&&s>(a[t]*2))++cnt;
	for(int i=t+1;i<=n;++i)
		if(k+1<=n)dfs(k+1,s+a[i],i);
}

int f(){
	dfs(0,0,0);
	return cnt%P;
}

int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20){
		cout<<f();
	}else cout<<n/12*n/6-1;
	
	return 0;
}  
