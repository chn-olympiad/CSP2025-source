#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
int a[maxn];
int c[3][maxn];
bool cmp(int x,int y){
	return x>y;
}
int vis[maxn];
long long ans=0;
long long check(){
	int cnt1=0,cnt2=0,cnt3=0;
	long long re=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			cnt1++;
		}else if(vis[i]==2){
			cnt2++;
		}else{
			cnt3++;
		}
		re+=c[vis[i]-1][i];
	}
	if((cnt1>(n/2))||(cnt2>(n/2))||(cnt3>(n/2))){
		return 0;
	}
	return re;
}
void dfs(int pos){
	if(pos==n+1){
		ans=max(ans,check());
		return ;
	}
	vis[pos]=1;
	dfs(pos+1);
	vis[pos]=2;
	dfs(pos+1);
	vis[pos]=3;
	dfs(pos+1);
	return ;
}
void s(){
	
	cin>>n;
	if(n<=10){
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>c[0][i]>>c[1][i]>>c[2][i];
		}
		dfs(1);
		cout<<ans<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>a[i]>>u>>v;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		s();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
