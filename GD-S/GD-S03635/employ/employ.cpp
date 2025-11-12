#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int ans;
bool vis[10005];
int arr[10005];
void dfs(int pos,int ma,int l,int ru){
	if(pos>=n){
		if(ma>=m){
			
			ans++;
		}
		return ;
	}else{
		
		for(int i=1;i<=n;i++){
		
			if(vis[i]){
				vis[i]=false;
				if(ru<arr[i]){
					if(s[l]=='1'){
						dfs(pos+1,ma+1,l+1,ru);
						
					}else{
						dfs(pos+1,ma,l+1,ru+1);
					}
				}else{
					dfs(pos+1,ma,l,ru);
					
				}
				vis[i]=true;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>s;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
		vis[i]=true;
	dfs(0,0,0,0);
	cout<<ans<<endl;
}
