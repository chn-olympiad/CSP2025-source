#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct stu{
	int id,x;
}a[100001][4];
bool cmp(stu x,stu y){
	return x.x>y.x;
}
void dfs(int x,int sum,int a1,int a2,int a3){
	if(a1>n/2||a2>n/2||a3>n/2){
		return;
	}
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(a[x][i].id==1){
			dfs(x+1,sum+a[x][i].x,a1+1,a2,a3);
		}
		else if(a[x][i].id==2){
			dfs(x+1,sum+a[x][i].x,a1,a2+1,a3);
		}
		else{
			dfs(x+1,sum+a[x][i].x,a1,a2,a3+1);
		}
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
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id=j;
			}
			stable_sort(a[i]+1,a[i]+4,cmp);
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
