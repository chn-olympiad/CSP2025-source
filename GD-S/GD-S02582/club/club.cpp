#include<bits/stdc++.h>
using namespace std;
long long n,t,cnt,ans,cnt1;
long long d1[100005],d2[100005],d3[100005],zong[100005][5],vis[10005];
void dfs(long long pos,long long sum,long long last,long long p1,long long p2,long long p3){
	if(pos==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(p1>n/2||p2>n/2||p3>n/2){
		return ;
	}
	for(int i=last;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(vis[i]==0){
				vis[i]=1;
				if(j==1){
					dfs(pos+1,sum+zong[i][j],i,p1+1,p2,p3);
				}
				if(j==2)dfs(pos+1,sum+zong[i][j],i,p1,p2+1,p3);
				if(j==3)dfs(pos+1,sum+zong[i][j],i,p1,p2,p3+1);
			}
		}
		vis[i]=0;
	}
}
void dfs2(){
	for(int i=1;i<=n;i++){
	        	if(d1[i]>d2[i]){
	        		ans+=d1[i];
				}
				if(d1[i]<d2[i]){
	        		ans+=d2[i];
				}
			}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		ans=0;
		cin>>n;
	    for(int i=1;i<=n;i++){
		cin>>zong[i][1]>>zong[i][2]>>zong[i][3];
		d1[i]=zong[i][1];
		d2[i]=zong[i][2];
		d3[i]=zong[i][3];
		if(zong[i][2]==0&&zong[i][3]==0){
			cnt++;
		}
		if(zong[i][3]==0){
			cnt1++;
		}
	    }
	    if(cnt==n){
	    	sort(d1+1,d1+n+1);
	    	for(int i=n;i>n/2;i--){
	    		ans+=d1[i];
			}
			cout<<ans;
			return 0;
	    }
	    if(cnt1==n){
	        dfs2();
	        cout<<ans;
			return 0;
	    }
	    dfs(1,0,1,0,0,0);
	    cout<<ans;
	}
	return 0;
} 
