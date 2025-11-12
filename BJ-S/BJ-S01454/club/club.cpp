#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct node{
	int x,y,z;
}a[N];

long long ans;
void dfs(int cur,int cnt1,int cnt2,int cnt3,long long sum){
	if( (cnt1>n/2) || (cnt2>n/2) || (cnt3>n/2) ){
		return;
	}
	if(cur>n){
		ans=max(ans,sum);
		return;
	}
	
	dfs(cur+1,cnt1+1,cnt2,cnt3,sum+a[cur].x);
	dfs(cur+1,cnt1,cnt2+1,cnt3,sum+a[cur].y);
	dfs(cur+1,cnt1,cnt2,cnt3+1,sum+a[cur].z);
	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
