#include<bits/stdc++.h>
using namespace std;
int t,n,ans,tot,fa,fb,sum[4],a[4][100010],za[100010];
void dfs(int c){
	ans=max(ans,tot);
	if(c>n) return;
	for(int i=1;i<=3;i++){
		sum[i]++;
		if(sum[i]<=n/2){
			tot+=a[i][c];
			dfs(c+1);
			tot-=a[i][c];
		}
		sum[i]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		fa=0,fb=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[3][i]!=0) fb=1;
			if(a[2][i]!=0||a[3][i]!=0) fa=1;
			za[i]=a[1][i];
		}
		if(fa==0){
			sort(za+1,za+1+n);
			for(int i=n;i>n/2;i--){
				ans+=za[i];
			}
			cout<<ans<<endl;
			continue;
		}
		sum[4]={0},tot=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
