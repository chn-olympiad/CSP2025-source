#include <bits/stdc++.h>
#define ll long long
const ll MAXN=2e5; 
using namespace std;
int t,n;
ll a[MAXN][4]; 
int vis[MAXN][4];
int mem[4];//k部门有几个人 
ll ans=0;
ll maxn(ll x,ll y){return x>y?x:y;}
void dfs(int bt,int k,int value){
	if(mem[k]>n/2){return ;}
	if(bt>=n){
		ans=maxn(ans,value);
		return ;
	}
	for(int i=1;i<=3;i++){
		vis[bt+1][i]=1;
		mem[i]++;
		dfs(bt+1,i,value+a[bt+1][i]);
		vis[bt+1][i]=0;
		mem[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		mem[1]=mem[2]=mem[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){	
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++){
			mem[i]++;
			dfs(1,i,a[1][i]);
			mem[i]--;
		}	
		cout<<ans<<endl;	
	}

	return 0;
} 

