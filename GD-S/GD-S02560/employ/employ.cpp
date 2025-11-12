#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=998244353;
int n,m,a[M],ans;
int p[M],sum[M],b[M];
string s;
void dfs(int x){
//	For(i,1,n) printf("%d ",p[i]);
//	printf("\n");
	if(x>n){
		For(i,1,n) printf("%d ",p[i]);
		printf("\n");
		ans=(ans+1)%inf;
		return;
	}
	For(i,1,n){
		if(!b[i]&&sum[x-1]<a[i]){
			b[i]=1;
			p[x]=a[i];
			dfs(x+1);
			p[x]=-1;
			b[i]=0;
		}
	}
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>s;
	For(i,1,n) p[i]=-1;
	For(i,1,n) sum[i]=sum[i-1]+(s[i-1]=='0');
	sum[0]=-1;
//	For(i,1,n) printf("%d ",sum[i]);
	For(i,1,n) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
4 2
1001
1 2 2 3

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
