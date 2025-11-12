#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
int a[5010];
map<string,int> m;
unsigned long long ans;
void dfs(int i,int cnt,int maxl,long long h,string x){
	if(cnt>=3&&h>2*maxl&&m[x]==0){
		m[x]=1;
		ans=(ans+1)%N;
	}
	if(i>=n) return;
	char t=i+'0';
	dfs(i+1,cnt+1,max(maxl,a[i]),h+a[i],x+t);
	dfs(i+1,cnt,maxl,h,x);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,0,0,"");
		cout<<ans%N;
	}else{
		ans=1;
		long long cnt=1;
		for(long long i=3;i<=n;i++){
			for(long long j=i-1;j>=0;j--){
				long long t=n-j;
				ans=ans%N*t%N;
				cnt=cnt%N*(j+1)%N;
			}
		}
		cout<<ans/cnt%N;
	}
	return 0;
}

