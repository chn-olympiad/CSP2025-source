#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010];
int mi(int z){
	int ans=1;
	for(int i=0;i<z;i++){
		ans*=2;
		ans%=mod;
	}
	return ans;
} 
int dfs(int p,int he,int maxx,int d){
	he+=a[p];d++;
	if(he>maxx&&d>=2)return mi(p-1);
	if(he<=maxx&&p==1)return 0;
	int ans=0;
	for(int i=p-1;i>0;i--){
		int tmp=dfs(i,he,maxx,d);
		ans+=tmp;
		ans%=mod;
		if(tmp==0)break;
	}
	return ans;
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int answer=0;
	for(int i=3,maxx;i<=n;i++){
		maxx=a[i];
		answer+=dfs(i,0,2*maxx,-1);
		answer%=mod;
	}
	answer%=mod;
	cout<<answer;
	return 0;
}
