#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[4][100010];
int v[100010];
int f1=1;
int ans1=0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x1,int x2,int x3,int sum){
	if(x1+x2+x3==n){
		ans1=max(ans1,sum);
		return;
	}
	if(x1+1<=n/2){
		dfs(x1+1,x2,x3,sum+a[1][x1+x2+x3+1]);
	}
	if(x2+1<=n/2){
		dfs(x1,x2+1,x3,sum+a[2][x1+x2+x3+1]);
	}
	if(x3+1<=n/2){
		dfs(x1,x2,x3+1,sum+a[3][x1+x2+x3+1]);
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0){
				f1=0;
			}
		}
		if(f1==1){
			long long summ=0;
			sort(a[1]+1,a[1]+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				summ+=a[1][i];
			}
			cout<<summ<<endl;
			continue;
		}
		ans1=0;
		dfs(0,0,0,0);
		cout<<ans1<<endl;
	} 
	return 0;
} 
