#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;
struct ww{
	int x,y,z;
}a[maxn];
int n,maxx;
void dfs(int x,int sum,int X,int Y,int Z){
	if((x-1)>n){
		return ;
	}
	if((X+Y+Z)==n){
		maxx=max(maxx,sum);
	} 
	if(X<(n/2)){
		dfs(x+1,sum+a[x].x,X+1,Y,Z);
	}
	if(Y<(n/2)){
		dfs(x+1,sum+a[x].y,X,Y+1,Z);
	}
	if(Z<(n/2)){
		dfs(x+1,sum+a[x].z,X,Y,Z+1);
	}
	return ;
}
bool vis[maxn]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		maxx=0;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z==0){
				;
			}else{
				flag=0;
			}
		}
		if(flag){
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=max(a[i].x,max(a[i].y,a[i].z));
			}
			cout<<cnt<<"\n";
		}else{
			dfs(1,0,0,0,0);
			cout<<maxx<<"\n";
		}
	}
	return 0;
}//Ren5Jie4Di4Ling5%

