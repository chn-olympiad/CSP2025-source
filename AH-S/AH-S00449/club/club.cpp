#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>b.y;
	return a.z>b.z;
}
int ans;
void dfs(int idx,int cnta,int cntb,int cntc,int sum){
	if(idx==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnta+1<=n/2){
		dfs(idx+1,cnta+1,cntb,cntc,sum+a[idx].x);
	}
	if(cntb+1<=n/2){
		dfs(idx+1,cnta,cntb+1,cntc,sum+a[idx].y);
	}
	if(cntc+1<=n/2){
		dfs(idx+1,cnta,cntb,cntc+1,sum+a[idx].z);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		if(n<=10){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}else if(a[1].y==a[1].z&&a[1].z==0){
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			cout<<sum<<"\n";
			continue;
		}
		int ans=0;
		int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(cnta<n/2){
					 ans+=a[i].x;
					 cnta++;
				 } else if(a[i].y>=a[i].z){
					if(cntb<n/2){
						ans+=a[i].y;
						cntb++;
					}else{
						ans+=a[i].z;
						cntc++;
					}
				}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(cntb<n/2){
					 ans+=a[i].y;
					 cntb++;
				 } else if(a[i].x>=a[i].z){
					if(cnta<n/2){
						ans+=a[i].x;
						cnta++;
					}else{
						ans+=a[i].z;
						cntc++;
					}
				}
			}
			if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				if(cntc<n/2){
					 ans+=a[i].z;
					 cntc++;
				 } else if(a[i].x>=a[i].y){
					if(cnta<n/2){
						ans+=a[i].x;
						cnta++;
					}else{
						ans+=a[i].y;
						cntb++;
					}
				}
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
}
