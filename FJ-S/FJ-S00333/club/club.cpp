#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][3];
int ans;
int cnt[5];
void dfs(int x,int s){
	if(x==n+1){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(x+1,s+a[x][i]);
			cnt[i]--;
		}
	}
}
bool pd1(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0)return false;
	}
	return true;
}
void solve1(){
	int b[100005];
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=n/2+1;i--){
		ans+=b[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n<=10)dfs(1,0);
		else if(pd1())solve1();
		cout<<ans<<endl;
	}
	return 0;
}

