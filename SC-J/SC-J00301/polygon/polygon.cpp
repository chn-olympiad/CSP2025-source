#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n;
int a[N];
int ans=0;
void dfs(int x,int num,int maxx,int y/*已选边数*/,int b/*边数*/){
//	printf("%d %d %d %d %d\n",x,num,maxx,y,b);
	if(x>n) return ;
	if(y>b) return ;
	if(y==b){
		if(num>maxx*2){
			ans++;
			ans%=mod;
			return ;
		}
	}
	dfs(x+1,num+a[x+1],max(maxx,a[x+1]),y+1,b);
	dfs(x+1,num,maxx,y,b);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int num=0;
		int maxx=0;
		for(int i=1;i<=n;i++){
			num+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(num>maxx*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	bool s1=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			s1=0;
			break;
		}
	}
	if(s1==1){
		cout<<n-2;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,0,0,0,i);
	}
	cout<<ans;
	return 0;
}
//written by smartjohn
