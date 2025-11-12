#include<bits/stdc++.h>
using namespace std;
int n,a[100005],t;
struct node{
	int x1,x2,x3;
}x[100000];
long long ans;
void dfs(int k,int y,int e,int s){
	if(k==n){
		long long sum=0;
		for(int i=0;i<n;i++){
			if(a[i]==1) sum+=x[i].x1;
			else if(a[i]==2) sum+=x[i].x2;
			else sum+=x[i].x3;
		}
		ans=max(ans,sum);
	}else{
		for(int i=1;i<=3;i++){
			if(y==n/2&&i==1) continue;
			if(e==n/2&&i==2) continue;
			if(s==n/2&&i==3) continue;
			a[k]=i;
			if(i==1) dfs(k+1,y+1,e,s);
			else if(i==2) dfs(k+1,y,e+1,s);
			else dfs(k+1,y,e,s+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		for(int i=0;i<n;i++) cin>>x[i].x1>>x[i].x2>>x[i].x3;
		ans=0;
		dfs(0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
