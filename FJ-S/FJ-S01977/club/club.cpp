#include<bits/stdc++.h>
using namespace std;
long long a[100005][4],n,t,most,ans,nu[4];
void dfs(int num){
	if(num==n){
		if(ans>most){
			most=ans;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		if(nu[i]>=n/2){
			continue;
		}
		ans+=a[num+1][i];
		nu[i]++;
		dfs(num+1);
		nu[i]--;
		ans-=a[num+1][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		most=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(0);
		cout<<most<<endl;
	}

	return 0;
}

