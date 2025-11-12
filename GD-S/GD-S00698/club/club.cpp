#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,t,sat[maxn][4],ans,n2,club_num[4];
void dfs(ll num,ll sum){
	ans=max(ans,sum);
	if(num>n){
		return;	
	}
	for(int i=1;i<=3;i++){
		if(club_num[i]>=n2)continue;
		club_num[i]++;
		dfs(num+1,sum+sat[num][i]);
		club_num[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0; 
		memset(club_num,0,sizeof(club_num));
		memset(sat,0,sizeof(sat));
		cin>>n;
		n2=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>sat[i][j];
			}
		}
		dfs(0,0);
		cout<<ans<<'\n';
	}	
	return 0;
} 
