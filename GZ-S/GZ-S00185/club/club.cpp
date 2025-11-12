//GZ-S00185 华东师范大学附属贵阳学校 彭梓垚 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
int t,n,a[N][4],ans;
int v[4];
int dfs(int x,int n,int ans){
	if(x>n){
		return ans;
	}
	int anss=ans;
	for(int i=1;i<=3;i++){
		if(v[i]>=n/2) continue;
		v[i]++;
		anss=max(anss,dfs(x+1,n,ans+a[x][i]));
		v[i]--;
	}
	return anss;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=3;i++) v[i]=0;
		ans=dfs(1,n,0);
		cout<<ans<<endl;
	}
	return 0;
}
