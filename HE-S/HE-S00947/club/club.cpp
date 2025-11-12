#include<bits/stdc++.h>
const int N = 1e5+5;
using namespace std;

int t,n;
int a[N][4];
long long ans,sum;
int k[4];

void dfs(int x){
	if(x>n){
		ans=max(sum,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(k[i]<n/2){
			k[i]++;
			sum+=a[x][i];
			dfs(x+1);
			sum-=a[x][i];
			k[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
