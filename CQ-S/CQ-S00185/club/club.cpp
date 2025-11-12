#include<bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;

const int N=1e5+10;
int n,m,bm[5]={0},mx=-1;
int a[N][5];
//string s;
//vector<int> G;


void dfs(int p,int sum){
	if(p-1==n){
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if((bm[i]+1)<=(n/2)){
			bm[i]++;
			dfs(p+1,sum+a[p][i]);
			bm[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		mx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(1,0);
		cout<<mx<<'\n'; 
	}
	
	
	return 0;
}
