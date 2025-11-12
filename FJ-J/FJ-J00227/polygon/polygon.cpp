#include<bits/stdc++.h>

using namespace std;

int n;
int a[5011];
long long res=0;
vector<int> g;

int dfs(int s,int u){
	if(u>n){
		if(g.size()==s){
			int cnt=0,mx=0;
			for(int i=0;i<g.size();i++){
				cnt+=a[g[i]];
				mx=max(mx,a[g[i]]);
			}
			if(cnt>mx*2){
				res++;
			}
		}
		
		return 0;
	}
	g.push_back(u);
	dfs(s,u+1);
	g.pop_back();
	dfs(s,u+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		if(mx*2<a[1]+a[2]+a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	
	for(int i=3;i<=n;i++){
		dfs(i,1);
	}
	cout<<res%998%244%353;
	return 0;
}
