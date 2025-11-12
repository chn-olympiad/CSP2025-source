#include<bits/stdc++.h>
using namespace std;

int n[5050];
int ans;
int sn;

void dfs(int cnt,int idx,int mx,int tim){
	if(cnt>=3){
		//cout<<"tim=="<<tim<<" mx=="<<mx;
		if(tim>mx*2){
			//cout<<"f==1";
			ans++;
		}
	//	cout<<"\n";
	}
	if(idx+1>sn){
		return;
	}
	dfs(cnt+1,idx+1,max(mx,n[idx]),tim+n[idx]);
	dfs(cnt,idx+1,mx,tim);
	return;
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>sn;
	for(int i=0;i<sn;i++){
		cin>>n[i];
	}
	dfs(0,0,0,0);
	cout<<ans%998%224%353;
	return 0;
}