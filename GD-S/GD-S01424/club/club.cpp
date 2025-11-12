#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int n;
long long ans=0;
void dfs(int x,long long sum,int d1,int d2,int d3){
	if(x==n+1){
		if(d1<=n/2&&d2<=n/2&&d3<=n/2){
			ans=max(ans,sum);		
		}
		return;
	}
	if(d1>n/2||d2>n/2||d3>n/2){
		return;
	}
	dfs(x+1,sum+a[x][1],d1+1,d2,d3);
	dfs(x+1,sum+a[x][2],d1,d2+1,d3);
	dfs(x+1,sum+a[x][3],d1,d2,d3+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int da2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==a[i][3]&&a[i][2]==0){
				da2++;
			}
		}
		if(n>=100000&&da2!=0){
			int da3=0;
			int da4[100005];
			for(int i=1;i<=n;i++){
				da4[i]=a[i][1];
			}
			sort(da4+1,da4+n+1,greater<int>());
			for(int i=1;i<=n/2;i++){
				da3+=da4[i];
			}
			cout<<da4;
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		ans=0;
	}
	return 0;
} 
