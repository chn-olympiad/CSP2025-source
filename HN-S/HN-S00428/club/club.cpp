#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
 /*freopen¼ÇµÃ¿ª 
 fffffffffffffffffffffffffffff
 rrrrrrrrrrrrrrrrrrrrrrrrrrrrr
 eeeeeeeeeeeeeeeeeeeeeeeeeeeee
 ooooooooooooooooooooooooooooo
 ppppppppppppppppppppppppppppp
 eeeeeeeeeeeeeeeeeeeeeeeeeeeee
 nnnnnnnnnnnnnnnnnnnnnnnnnnnnn
 */
int n;
int T;
struct node{
	int s1,s2,s3;
}a[N];

long long ans=0;
int vis[6];
void dfs(int idx,long long cnt){
	if(idx==n+1){
		ans=max(ans,cnt);
	} 
	
	if(vis[1]<n/2){
		vis[1]++;
		dfs(idx+1,cnt+a[idx].s1); 
		vis[1]--;
	}
	if(vis[2]<n/2){
		vis[2]++;
		dfs(idx+1,cnt+a[idx].s2); 
		vis[2]--;
	}
	if(vis[3]<n/2){
		vis[3]++;
		dfs(idx+1,cnt+a[idx].s3);  
		vis[3]--;
	}
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T; 
	while(T--){
		cin>>n;
		vis[1]=vis[2]=vis[3]=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]={x,y,z};
		}
		dfs(1,0ll);
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
