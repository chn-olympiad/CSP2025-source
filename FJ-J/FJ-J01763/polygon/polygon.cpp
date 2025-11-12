#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int MAXN=5005;
int a[MAXN];
long long ans=0;
void dfs(int now,int sum,int maxn,int maxx){
	if(now==maxx){
		return;
	}
	if(sum+a[now]>maxn){
		ans++;
		ans%=998244353;
	}
	dfs(now+1,sum+a[now],maxn,maxx);
	dfs(now+1,sum,maxn,maxx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		dfs(1,0,a[j],j);
	}
	cout<<ans;
	return 0;
} 
