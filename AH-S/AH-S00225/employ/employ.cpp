#include<bits/stdc++.h>
using namespace std;
int a[510],b[510],n,m;
long long ans=0;
bool f[510];
void dfs(int x,int y){
	if(x>n){
		ans+=y>=m;
		return ;
	}
	if(y+n-x<m) return ;
	for(int i=1; i<=n; i++)
		if(!f[i]){
			f[i]=1;
			dfs(x+1,y+(b[x]<a[i]));
			f[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1; i<=n; i++)
		b[i]=b[i-1]+1-s[i-1]+'0';
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(a[n]==1){
		printf("1\n");
		return 0;
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
//AFO
