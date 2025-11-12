#include<bits/stdc++.h>
using namespace std;

int n,ans;
int co[100001][4];
void dfs(int c1,int c2,int c3,int p,int sum){
	if(p==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(c1<n/2){
		c1++;
		sum+=co[p][1];
		p++;
		dfs(c1,c2,c3,p,sum);
		p--;
		sum-=co[p][1];
		c1--;
	}
	if(c2<n/2){
		c2++;
		sum+=co[p][2];
		p++;
		dfs(c1,c2,c3,p,sum);
		p--;
		sum-=co[p][2];
		c2--;
	}
	if(c3<n/2){
		c3++;
		sum+=co[p][3];
		p++;
		dfs(c1,c2,c3,p,sum);
		p--;
		sum-=co[p][3];
		c3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>co[i][1]>>co[i][2]>>co[i][3];
		}
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
