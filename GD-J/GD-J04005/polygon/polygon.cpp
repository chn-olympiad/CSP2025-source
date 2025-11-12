#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,ans=0,vis[1000005],s[100000][100][25];
void dfs(int cnt,int num,int now){
	if(cnt>num*2&&now>=3){
		if(s[cnt][num][now]==0){
			ans++;
			s[cnt][num][now]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0&&now<=5){
			vis[i]=1;
			dfs(cnt+a[i],max(num,a[i]),now+1);
			vis[i]=0;
		}
	}
	
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
 */
