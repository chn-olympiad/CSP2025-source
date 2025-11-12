#include<bits/stdc++.h>
using namespace std;
const long long MAXN=998244353;
int n,maxx=-1;
int a[5005],flag[5005];
void dfs(int start,int end,int k){
	if(k==end){
		for(int i=1;i<=n;i++){
			int sum=0,maxxs=-1;
			if(flag[i]!=-1){
				sum+=flag[i];
				sum%=MAXN;
				maxxs=max(flag[i],maxxs);
				maxxs%=MAXN;
			}
			if(sum>=(maxxs*2)){maxx=max(sum%MAXN,maxx%MAXN);}
		}
		return;
	}
	flag[start]=start;
	for(int i=start+1;i<=n;i++){
		flag[i]=i;
		dfs(i,end,k+1);
		flag[i]=-1;
	}
	flag[start]=-1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dfs(i,j,1);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
