#include<bits/stdc++.h>
using namespace std;
int n;
int a[105],ans=0;
void dfs1(int s,int mx,int cnt,int st){//想不出来,暴搜
	if(s>mx*2 && cnt>=3){
		ans++;
	}
	if(st==n) return;
	for(int i=st+1;i<=n;i++){
		dfs1(s+a[i],max(mx,a[i]),cnt+1,i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs1(0,0,0,0);
	cout<<ans;
	return 0; 
}
