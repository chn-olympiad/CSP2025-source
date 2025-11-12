#include<bits/stdc++.h>
using namespace std;
int n,k,Max=0;
int a[200006];
void dfs(int now,int cnt){
	int anow=now+1;
	if(now>=n+1){
		Max=max(Max,cnt);
		return; 
	}
	int xorcnt=0;
	while(xorcnt!=k&&now<=n||now==anow-1){ 
		xorcnt=xorcnt xor a[now];
		now++;
	}
	if(now<=n+1&&xorcnt==k){
		dfs(now,cnt+1);
	}
	if(anow<n+1){
		dfs(anow,cnt);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool k=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)k=0;
		if(a[i]==1){
			cnt++;
		}
	}
	if(k){
		cout<<cnt+1;
		return 0;
	}
	dfs(1,0);
	cout<<Max;
	fclose(stdin);
	fclose(stdout);
}
