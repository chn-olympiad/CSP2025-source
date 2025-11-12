#include<bits/stdc++.h>
using namespace std;
int a[100005][4],b[100005],ans,n;
void dfs(int sum,int d,int x,int y,int z){
	if(d==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(x+1<=n/2) dfs(sum+a[d][1],d+1,x+1,y,z);
	if(y+1<=n/2) dfs(sum+a[d][2],d+1,x,y+1,z);
	if(z+1<=n/2) dfs(sum+a[d][3],d+1,x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		if(n<=30){
			dfs(0,1,0,0,0);
			cout<<ans<<"\n";
		}else{
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=b[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
