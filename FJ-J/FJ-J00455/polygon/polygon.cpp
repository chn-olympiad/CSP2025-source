#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

int n,a[5005];

long long ans;

void dfs(int k,int sum,int mx){
	if(k>n){
		if(sum>2*mx)ans++;
		return ;
	}
	dfs(k+1,sum,mx);
	dfs(k+1,sum+a[k],a[k]);
}

int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}


























/*





*/
