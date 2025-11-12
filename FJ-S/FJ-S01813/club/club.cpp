#include <bits/stdc++.h>
using namespace std;
struct bt{
	int a;
	int b;
	int c;
}a[100005];
int ans=0;
void dfs(int q,int w,int e,int x,int y,int n){
	if(x>=1+n){
		ans=max(ans,y);
		return;
	}
	if(q+1<=n/2){
		dfs(q+1,w,e,x+1,y+a[x].a,n);
	}
	if(w+1<=n/2){
		dfs(q,w+1,e,x+1,y+a[x].b,n);
	}
	if(e+1<=n/2){
		dfs(q,w,e+1,x+1,y+a[x].c,n);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(0,0,0,1,0,n);   
		cout<<ans<<endl;
	}
	return 0;
}
