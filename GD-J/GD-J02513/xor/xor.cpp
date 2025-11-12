#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int ans=0;
struct node{
	int i;
	int j;
	int hlong;
};
vector<long long> a(500005,0);
vector<node> vis(500005,{0,0,0});
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int frog1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			frog1=0;
		}
	}
	if(frog1=1){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		int frog=1;
		for(int j=0;j<=n;j++){
			if(j==0 && frog==1){
				if(a[i]==k){
					if(vis[i].hlong==0){
						ans++;
					}
					for(int j=vis[i].i;j<=vis[i].j;j++){
						vis[j].i=0;
						vis[j].j=0;
						vis[j].hlong=0;
					}
					vis[i].hlong=1;
					vis[i].i=i;
					vis[i].j=i;
					frog=0;
					break;
				}
			}
			else if(frog==1){
				if(vis[j].hlong==0 || j<vis[i].j){
				    sum=sum^a[j];
				    if(sum==k){
					    if(vis[j].hlong==0 && vis[i].hlong==0){
				    		ans++;
					    }
					    for(int k=vis[i].i;k<=vis[i].j;k++){
					    	vis[k].i=0;
				    		vis[k].j=0;
				    		vis[k].hlong=0;
				    	}
				    	for(int l=i;i<=j;l++){
				    		vis[l].hlong=j-i+1;
				    		vis[l].i=i;
				    		vis[l].j=j;
						}
			    		frog=0;
			    		break;
			    	}
				}
			}
		}
	}
	cout<<ans; 
	return 0;
}
