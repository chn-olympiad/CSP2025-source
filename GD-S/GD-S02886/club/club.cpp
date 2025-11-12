#include<iostream>
#include<cmath>
using namespace std;
int t,n,a[100005][4],v[3],maxn=-1;
void dfs(int id,int sum){
	if(id==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(v[1]+1<=n/2){
		v[1]++;
		dfs(id+1,sum+a[id][1]);
		v[1]--;
	}
	if(v[2]+1<=n/2){
		v[2]++;
		dfs(id+1,sum+a[id][2]);
		v[2]--;
	}
	if(v[3]+1<=n/2){
		v[3]++;
		dfs(id+1,sum+a[id][3]);
		v[3]--;
	}
}
int main(){
	cin>>t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int z=1;z<=t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		maxn=-1;
		dfs(1,0);
		cout<<maxn<<endl;
	}
	return 0;
} 
