#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int t,n,ans;
int e[N][3],num[3];
void dfs(int k,int sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(num[i]==n/2) continue;
		num[i]++;
		dfs(k+1,sum+e[k][i]);
		num[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>e[i][0]>>e[i][1]>>e[i][2];
		ans=0;
		num[0]=num[1]=num[2]=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
