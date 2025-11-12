#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;

int T,n,res,ans;
int cnt[4];
int vc[N][4];

void dfs(int cur){
	if(cur>n){
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)return ;
		ans=max(ans,res);
		return ;
	}
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)return ;
	for(int i=1;i<=3;i++){
		res+=vc[cur][i];
		cnt[i]++;
		dfs(cur+1);
		res-=vc[cur][i];
		cnt[i]--;
	}
	ans=max(ans,res);
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		res=0;
		memset(cnt,0,sizeof(cnt));
		memset(vc,0,sizeof(vc));
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&vc[i][1],&vc[i][2],&vc[i][3]);
		dfs(1);
		cout<<ans;
	}
	
	return 0;
}
