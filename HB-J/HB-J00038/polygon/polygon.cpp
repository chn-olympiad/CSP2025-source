#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
//40
int n,cnt;
int a[78];
bool book[78];
//x is id
//sum is num
void dfs(int x,int mx,int sum,int step){
	//cout<<x<<' '<<sum<<' '<<mx<<' '<<cnt<<endl;
	if(sum>a[mx]&&step>=2){
		cnt++;
	}
	for(int i=x+1;i<mx;i++){
		dfs(i,mx,sum+a[i],step+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
		cnt%=mod;
	}
	printf("%lld",cnt);
	return 0;
}
