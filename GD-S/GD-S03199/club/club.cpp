#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][4];
int ans;
int cnt[4];
int k=0;
void dfs(int step)
{
	if(step==n+1){
		k=max(ans,k);
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			ans+=a[step][i];
			dfs(step+1);
			cnt[i]--;
			ans-=a[step][i];
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=0;k=0;
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
		dfs(1);
		memset(a,0,sizeof(a));
		cout<<k;
		cout<<"\n";
	}
	return 0;
}
