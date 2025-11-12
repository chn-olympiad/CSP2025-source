#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
int arr[N][5];
int n;
int mark[50];
long long mx=-1;
void dfs(int dep,int a,int b,int c){
	if(dep==n+1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=arr[i][mark[i]];
		}
		mx=max(mx,sum);
	}
	if(a+1<=n/2){
		mark[dep]=1;
		dfs(dep+1,a+1,b,c);
	}
	if(b+1<=n/2){
		mark[dep]=2;
		dfs(dep+1,a,b+1,c);
	}
	if(c+1<=n/2){
		mark[dep]=3;
		dfs(dep+1,a,b,c+1);
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int sum0=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			
		}
		mx=-1;
		dfs(1,0,0,0);
		cout<<mx<<'\n';
	}
} 
/*
1 
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

