#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=1,le=0;
int a[500100];
vector<int> flag(500100,-1);
void dfs(int start,int end,int k);
vector<pair<int,int>> ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int l=i;l<=j;l++){
				sum=(sum^a[l]);
			}
			if(sum==k){ans.push_back({i,j});le++;}
		}
	}
	for(int i=0;i<=le-1;i++){
		for(int j=0;j<=le-1;j++){
			dfs(i,j,1);
		}
	}
	cout<<cnt+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(int start,int end,int k){
	if(k==end){
		bool f=true;
		vector<bool> fl(500100,false);
		for(int i=1;i<=n;i++){
			if(flag[i]!=-1){
				for(int j=ans[flag[i]].first;j<=ans[flag[i]].second;i++){
					if(fl[j]==false){fl[j]=true;}
					if(fl[j]==true){f=false;}
				}
			}
		}
		if(f)cnt=max(cnt,end);
		return;
	}
	flag[start]=start;
	for(int i=start+1;i<=n;i++){
		flag[i]=i;
		dfs(i,end,k+1);
		flag[i]=-1;
	}
	flag[start]=-1;
}
