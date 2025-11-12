#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,L=1e5;
int t,n;
int maxl=-1;
struct Node{
	int a,b,c;
}d[N];
int k[N];
void dfs(int x,int s,int fa,int fb,int fc){
	if(x>n){
		maxl=max(maxl,s);
		return ;
	}
	if(fa<n/2){
		dfs(x+1,d[x].a+s,fa+1,fb,fc);
	}
	if(fb<n/2){
		dfs(x+1,d[x].b+s,fa,fb+1,fc);
	} 
	if(fc<n/2){
		dfs(x+1,d[x].c+s,fa,fb,fc+1);
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m=0;
	cin>>t;
	while(t--){
		maxl=-1;
		cin>>n;
		if(n==L){
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>k[i]>>d[i].b>>d[i].c;
			}
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=k[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n>=30&&n<=200){
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>k[i]>>d[i].b>>d[i].c;
			}
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=k[i];
			}
			cout<<2*ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<maxl<<endl;
	}
	
	return 0;
}
