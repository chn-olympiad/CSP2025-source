#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
int sum,ma,ans,maxx;
int x;
const int MOD=998244353;
void dfs(int k,int s,int step,int wei){
	if(k==x){
		if(s>2*wei) ans++;
		return;
	}
	else{
		for(int i=step;i<=n;i++){
			dfs(k+1,s+a[i],i+1,a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}
	else{
		if(n==3){
			if(sum>2*maxx) cout<<1;
			else cout<<0;
		} else{
			x=3;
			while(x<=n){
				dfs(0,0,1,0);
				ma=0;
				x++;
			}
			cout<<ans%MOD;
		}
	}
	return 0;
}