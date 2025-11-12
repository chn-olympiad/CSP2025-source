#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+10;
struct enn{
	int a,b,c;
};
int a[N][5];
int n;
int ans=0;
void dfs(int x,int sum,int x1,int x2,int x3){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x1<n/2){
		dfs(x+1,sum+a[x][1],x1+1,x2,x3);
	}
	if(x2<n/2){
		dfs(x+1,sum+a[x][2],x1,x2+1,x3);
	}
	if(x3<n/2){
		dfs(x+1,sum+a[x][3],x1,x2,x3+1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		bool A=false;
		bool B=false;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				A=true;
			}
			if(a[i][3]!=0)B=true;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		//特殊性质A
		if(!A){
			vector<int>g;
			for(int i=1;i<=n;i++){
				g.push_back(a[i][1]);
			}
			sort(g.begin(),g.end());
			for(int i=n-1;i>0&&n-i<=n/2;i--){
				ans+=g[i];
			}
			cout<<ans<<'\n';
			continue;
		}
//		if(!B){
//			
//		}
		//C各不相同 
		
	} 
	return 0;
}
