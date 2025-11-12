#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,d[5],a[N][5];
unsigned long long res,ans;
void dfs(int s){
	if(s>n){
		ans=max(ans,res);
		return ;
 	}
	for(int j=1;j<=3;j++){
		if(d[j]<n/2){
			d[j]++;
			res+=a[s][j];
			dfs(s+1);
			d[j]--;
			res-=a[s][j];
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		res=0,ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

