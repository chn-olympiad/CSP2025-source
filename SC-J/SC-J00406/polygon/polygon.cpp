#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void read(int &x){
	char c=getchar();x=0;
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-48,c=getchar();
}
void write(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>=10) write(x/10);
	putchar((char)(x%10+48));
}
const int N=5e3+5,mod=998244353;
int a[N],ans,sum[N],n;
void dfs(int x,int sum1,int maxx) {
	if(x==0) {
		if(sum1>2*maxx) ans++,ans%=mod;
		return ;
	}
	dfs(x-1,sum1,maxx);
	dfs(x-1,sum1+a[x],max(maxx,a[x]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(n,0,0);
	cout<<ans;
	return 0;
}