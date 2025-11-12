#include<bits/stdc++.h>
using namespace std;
#define int long long 
int p;
int n;
int arr[10005];
int ans;
int dij;
void dfs(int fla,int ppw,int ma,int pos){
	if(fla>=3){
		if(ppw>2*ma){
			ans=ans+1;
		}
	}
	if(fla==n || pos==n){
		return ;
	}
	for(int i=pos+1;i<=n;i++){
		dfs(fla+1,ppw+arr[i],max(ma,arr[i]),i);
	
		
	}
}
signed main(){
	freopen("r","polygon.in",stdin);
	freopen("w","polygon.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ans=0;
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
