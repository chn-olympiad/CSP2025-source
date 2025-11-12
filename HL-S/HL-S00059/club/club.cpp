#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n;
struct node{
	int a,b,c;
}p[N];
int maxx;
void dfs(int na,int nb,int nc,int cur,int sum){
	if(cur==n){
		maxx=max(maxx,sum);
	}
	if(na<n/2) dfs(na+1,nb,nc,cur+1,sum+p[cur+1].a);
	if(nb<n/2) dfs(na,nb+1,nc,cur+1,sum+p[cur+1].b);
	if(nc<n/2) dfs(na,nb,nc+1,cur+1,sum+p[cur+1].c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		maxx=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(0,0,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}

