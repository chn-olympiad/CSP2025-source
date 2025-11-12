#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a,b,c;
int ans=0;
struct node{
	int x,y,z;
}mp[100001];
bool cmp1(node a,node b){
	return a.x >b.x ;
}
void dfs(int x){
	if(a.size()>n/2||b.size()>n/2||c.size()>n/2){
		return ;
	}
	if(x==n+1){
		int sum=0;
		for(int i:a){
			sum+=mp[i].x ;
		}
		for(int i:b){
			sum+=mp[i].y ;
		}
		for(int i:c){
			sum+=mp[i].z ;
		} 
		ans=max(ans,sum);
		return ; 
	}
	a.push_back(x);
	dfs(x+1);
	a.pop_back();
	b.push_back(x);
	dfs(x+1);
	b.pop_back();
	c.push_back(x);
	dfs(x+1);
	c.pop_back();
}
int f=2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>mp[i].x >>mp[i].y >>mp[i].z ;
			if(mp[i].y !=0)f=0;
			if(mp[i].z !=0)f=1;
		}
		if(f==2){
			sort(mp+1,mp+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=mp[i].x ;
			}
			cout<<ans<<endl;
		}
		else{
			dfs(1);
			cout<<ans<<endl;
			ans=0;
		}
		
	}
	
	return 0;
}

