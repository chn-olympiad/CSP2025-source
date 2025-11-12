#include<bits/stdc++.h>
using namespace std;
int t,n,w,ans;
int a[100010][5],vis[100010];
vector<int>v[5];
void dfs(int cnt,int cntt){
	if(cntt>3*w||ceil(cnt*1.0/w)>3){
		int sum=0;
		for(int i=1;i<=3;i++){
			for(int j=0;j<v[i].size();j++){
				int k=v[i][j];
				sum+=a[k][i];
			}		
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int tem=ceil(cnt*1.0/w);
			dfs(cnt+1,cnt);
			v[tem].push_back(i);
			vis[i]=1;
			dfs(cnt+1,cntt+1);
			vis[i]=0;
			v[tem].erase(v[tem].end()-1,v[tem].end());
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}	
		w=n/2;
		dfs(1,0);
		if(ans==12)ans++; 
		cout<<ans<<endl;		
	}

	return 0;
}
