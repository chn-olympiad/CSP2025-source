#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005][5],culb[5],mm[1000005];
long long ans;
void dfs(int x,long long sum){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(culb[i]+1<=n/2){
			culb[i]++;
			dfs(x+1,sum+a[x+1][i]);
			culb[i]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t>0){
		int pp=0;
		ans=0;
		t--;
		scanf("%d",&n);
		for(int i=1;i<=3;i++)culb[i]=0;
		for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][2]==0&&a[i][3]==0){
			mm[++pp]=-a[i][1];
		}	
		}
		if(pp==n){
			sort(mm+1,mm+1+pp);
			for(int i=1;i<=n/2;i++){
				ans+=-mm[i];
			}
		}else{
		dfs(0,0);	
		}
		cout<<ans<<endl;
	}
	return 0;
}
