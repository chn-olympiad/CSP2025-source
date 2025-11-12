#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
int ma=INT_MIN;
void dfs(int m,int ans,int x,int y,int z){
	if(m==n+1){
		if(x<=n/2&&y<=n/2&&z<=n/2)
			ma=max(ma,ans);
		return;
	}
	dfs(m+1,ans+a[m][1],x+1,y,z);
	dfs(m+1,ans+a[m][2],x,y+1,z);
	dfs(m+1,ans+a[m][3],x,y,z+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int xza=1,xzb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])
				xza=0;
			if(a[i][3])
				xzb=0;
		}
		if(xza){//性质A 5分 
			int b[n+5],ans=0;
			memset(b,0,sizeof(b));
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--)
				ans+=b[i];
			cout<<ans<<"\n";
		}else{//可能20分 
			ma=0;
			dfs(1,0,0,0,0);
			cout<<ma<<"\n";
		}
	} 
	return 0; 
} 
//stO CCF Orz 
//估分总分50左右
