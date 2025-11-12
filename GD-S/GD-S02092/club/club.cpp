#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

long long n,T,ans,a[N][5],idnum[4],k,MAXN[N],last[N];

void dfs(long long sum,long long num){
	if (last[num]+sum<=ans) return;
	for (int i=1;i<=3;i++)
		if (idnum[i]>k) return;
	if (num==n+1) ans=max(sum,ans);
	
	for (int i=1;i<=3;i++){
		idnum[i]++;
		dfs(sum+a[num][i],num+1);
		idnum[i]--;
	}
	
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while (T--){
		cin>>n;
		k=n/2;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			MAXN[i]=max(a[i][3],max(a[i][1],a[i][2]));
		}
		for (int i=n;i>=1;i--) last[i]=last[i+1]+MAXN[i];
		
		dfs(0,1);
		cout<<ans<<endl;
		
		ans=0;
		for (int i=1;i<=3;i++) idnum[i]=0;
	}
	
	return 0;
}
