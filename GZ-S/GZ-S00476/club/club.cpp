//GZ-S00476 贵阳新世界学校 陈睿泽 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[4][N],ans1;
void dfs(int na,int nb,int nc,int ans,int la){
	if(na<=n/2){
		dfs(++na,nb,nc,ans+=a[1][++la],la);
	    ans1=max(ans,ans1);
	}
	if(nb<=n/2){
		dfs(na,++nb,nc,ans+=a[2][++la],la);
		ans1=max(ans,ans1);
	}
	if(nc<=n/2){
		dfs(na,nb,++nc,ans+=a[3][++la],la);
		ans1=max(ans,ans1);
    }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	ans1=0;
    	cin>>n;
    	for(int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i];
    	dfs(0,0,0,0,0);
    	cout<<ans1<<endl;
	}	
	return 0;
}





