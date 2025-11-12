#include<bits/stdc++.h>
using namespace std;
struct data1{
	int a,b,c;
}a[500010];
int T,n,maxn=0,vis[4];
void dfs(int x,int m){
	if(x==n+1){
		maxn=max(maxn,m);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]){
			vis[i]--;
			if(i==1){
				dfs(x+1,m+a[x].a);
			}	
			else if(i==2){
				dfs(x+1,m+a[x].b);
			}
			else if(i==3){
				dfs(x+1,m+a[x].c);
			}
			vis[i]++;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=3;i++){
			vis[i]=n/2;
		} 
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c; 
		}
		dfs(1,0);
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
