#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],ans=0,maxx=INT_MIN,cnt;
void dfs(long long k,long long ans,long long la,long long lb,long long lc){
	if(k>n){
		maxx=max(maxx,ans);
		return;
	}
	if(la<n/2){
		dfs(k+1,ans+a[k][1],la+1,lb,lc);
	}
	if(lb<n/2){
		dfs(k+1,ans+a[k][2],la,lb+1,lc);
	}
	if(lc<n/2){
		dfs(k+1,ans+a[k][3],la,lb,lc+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}