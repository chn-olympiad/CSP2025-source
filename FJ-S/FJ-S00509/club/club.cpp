#include<bits/stdc++.h>
using namespace std;
int a[100155][4];
int n;
int t;
long long maxn=-1;
void dfs(int x,long long ans,int A,int B,int C){
	if(x==n+1){
			maxn=max(maxn,ans);
			return ;
	}
		if(A<n/2)
		dfs(x+1,ans+a[x][1],A+1,B,C);
		if(B<n/2)
		dfs(x+1,ans+a[x][2],A,B+1,C);
		if(C<n/2)
		dfs(x+1,ans+a[x][3],A,B,C+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];	
		}
		maxn=-1;
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
} 
