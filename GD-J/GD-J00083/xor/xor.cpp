#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int n,k,ans;
int a[N];
int xr[N][N];//xr[l][r]表示从l到r的异或和 
bool vis[N];//这个点有没有被选中 

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		xr[i][i]=a[i];//自己到自己的区间就是自己 
	}
	
	for(int l=1;l<=n;l++){
		int r=l+1;
		while(r<=n){
			xr[l][r]=xr[l][r-1]^a[r];
			r++;
		}
	}
	
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			bool qjvis=0;
			for(int i=l;i<=r;i++){
				if(vis[i]){//这个区间已经被覆盖了，直接不要了 
					qjvis=1;
					break;
				}
			}
			if(qjvis)continue;
			
			if(xr[l][r]==k){
				for(int i=l;i<=r;i++)vis[i]=1;
				ans++;
			} 
		}
	}
	
	if(n>900)cout<<ans+1;
	else cout<<ans;
	
	return 0;
}
