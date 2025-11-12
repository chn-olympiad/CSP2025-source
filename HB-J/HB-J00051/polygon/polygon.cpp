#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,ans,sum,maxn;
int a[N],b[N];
bool check(int x){
	sum=0,maxn=0;
	for(int i=1;i<=x;i++){
		sum+=b[i];
		maxn=max(maxn,b[i]);
	}
	if(sum>maxn*2){
		return true;
	}
	return false;
}
void dfs(int x,int step,int last){
	if(step==x){
		if(check(x)){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		b[step+1]=a[i];
		dfs(x,step+1,i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
}
