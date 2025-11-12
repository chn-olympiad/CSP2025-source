#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
int cnt1,cnt2,cnt3;
int n;
long long ans;
int cs;
int t[N];
void dfs(int x,long long num){
	cs++;
	if(x>n){
		ans=max(ans,num);
		return ;
	}
	if(cnt1<n/2){
		cnt1++;
		dfs(x+1,num+a[x][1]);
		cnt1--;
	}
	if(cnt2<n/2){
		cnt2++;
		dfs(x+1,num+a[x][2]);
		cnt2--;
	}
	if(cnt3<n/2){
		cnt3++;
		dfs(x+1,num+a[x][3]);
		cnt3--;
	}
	return ;
}
void solve(){
	ans=0;
	cnt1=cnt2=cnt3=0;
	cin>>n;
	int flag=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=3; j++){
			cin>>a[i][j];
			if(a[i][2]!=0||a[i][3]!=0)flag=1;
		}
	}
	if(flag==0){
		int cnt=0;
		for(int i=1; i<=n; i++){
			t[++cnt]=a[i][1];
		}
		sort(t+1,t+1+cnt);
		for(int i=cnt; i>cnt/2; i--){
			ans+=t[i];
		}
		cout<<ans<<'\n';
		return ;
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
//	cout<<cs;
	return 0;
} 
