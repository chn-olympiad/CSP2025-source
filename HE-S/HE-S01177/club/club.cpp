#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans=-1; 
struct node{
	int a1;
	int a2;
	int a3;
	bool b;
}a[N];
void dfs(int x,int y,int z,int u){
	if(x+y+z==n){
		if(x<=(n/2) && y<=(n/2) && z<=(n/2)){
			ans=max(ans,u);
		}return;
	}for(int i=1;i<=n;i++){
		if(a[i].b){
			a[i].b=false;
			dfs(x+1,y,z,u+a[i].a1);
			dfs(x,y+1,z,u+a[i].a2);
			dfs(x,y,z+1,u+a[i].a3);
			a[i].b=true;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].b=true;
		}dfs(0,0,0,0);
		cout<<ans<<endl;
	}
	
	return 0;
}

