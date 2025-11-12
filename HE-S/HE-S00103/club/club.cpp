#include<bits/stdc++.h>
using namespace std;
int t,n;
struct D{
	int a,b,c;
}x[100001];
int ans=0;
void dfs(int m,int cnt,int a,int b,int c){
	if(m>n){
		ans=max(ans,cnt);
		return;
	}
	if(a<n/2){
		dfs(m+1,cnt+x[m].a,a+1,b,c);
	}
	if(b<n/2){
		dfs(m+1,cnt+x[m].b,a,b+1,c);
	}
	if(c<n/2){
		dfs(m+1,cnt+x[m].c,a,b,c+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
