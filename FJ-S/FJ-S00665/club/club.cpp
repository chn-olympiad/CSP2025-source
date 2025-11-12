#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,maxn;
int a[5][N];

void dfs(int p,int sum,int a1,int a2,int a3){
	if(p>n){
		maxn=max(sum,maxn);
		return;
	}
	if(a1<n/2)dfs(p+1,sum+a[1][p],a1+1,a2,a3);
	if(a2<n/2)dfs(p+1,sum+a[2][p],a1,a2+1,a3);
	if(a3<n/2)dfs(p+1,sum+a[3][p],a1,a2,a3+1);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		if(n<=10){
			dfs(1,0,0,0,0); 
		}
		else{
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>=n/2;i--)maxn+=a[1][i];
		}
		cout<<maxn<<endl;
	}
	return 0;
}
