#include<bits/stdc++.h>
using namespace std;
int anc[205][4],ans=0,n,nc1[205];
void dfs(int cnt,int step,int a,int b,int c){
	if(step==n){
		ans=max(ans,cnt);
		return;
	}
	if(a==n/2){
		dfs(cnt+anc[step][1],step+1,a,b+1,c);
		dfs(cnt+anc[step][2],step+1,a,b,c+1);
		return ;
	}
	else if(b==n/2){
		dfs(cnt+anc[step][0],step+1,a+1,b,c);
		dfs(cnt+anc[step][2],step+1,a,b,c+1);
		return ;
	}
	else if(c==n/2){
		dfs(cnt+anc[step][1],step+1,a,b+1,c);
		dfs(cnt+anc[step][0],step+1,a+1,b,c);
		return ;
	}
	else{
		dfs(cnt+anc[step][1],step+1,a,b+1,c);
		dfs(cnt+anc[step][0],step+1,a+1,b,c);
		dfs(cnt+anc[step][2],step+1,a,b,c+1);
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1=0,cnt2=0;
		for (int i=0;i<n;i++){
			cin>>anc[i][0]>>anc[i][1]>>anc[i][2];
			nc1[i]=anc[i][0];
			if(anc[i][2]==0 && anc[i][1]==0){
				cnt1++;
			}
		}
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
