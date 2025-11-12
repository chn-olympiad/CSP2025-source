#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,t,arr[N][11],cnt[11],t_ans;
void dfs(int nw,int ans){
	if(nw>n){
		t_ans=max(t_ans,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2) continue;
		cnt[i]++,ans+=arr[nw][i];
		dfs(nw+1,ans);
		cnt[i]--,ans-=arr[nw][i];
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		t_ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>arr[i][j];
			}
		}
		dfs(1,0);
		cout<<t_ans<<"\n";
	}
	return 0;
}
/*
club±©Á¦°æ 

Ô¸´ËĞĞ,ÖÕµÖÈºĞÇ ÈªÃÅÓÀ´æ 
I love ldyy
icebird_ldyy code
*/
