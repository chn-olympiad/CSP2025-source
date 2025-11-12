#include<bits/stdc++.h>
using namespace std;
namespace code{
//	#define int long long
	#define maxn 100005
	int n,ans=0;
	struct node{
		int x,y,z;
	}aa[maxn];	
	void dfs(int u,int sum,int a,int b,int c){
		if(a+b+c==n){
			ans=max(ans,sum);
			return ;
		}
		if(a==n/2){
			dfs(u+1,sum+aa[u].z,a,b,c+1);
			dfs(u+1,sum+aa[u].y,a,b+1,c);
		}else if(b==n/2){
			dfs(u+1,sum+aa[u].x,a+1,b,c);
			dfs(u+1,sum+aa[u].z,a,b,c+1);
		}else if(c==n/2){
			dfs(u+1,sum+aa[u].x,a+1,b,c);
			dfs(u+1,sum+aa[u].y,a,b+1,c);
		}else{
			dfs(u+1,sum+aa[u].x,a+1,b,c);
			dfs(u+1,sum+aa[u].y,a,b+1,c);
			dfs(u+1,sum+aa[u].z,a,b,c+1);
		}
	}
	bool cmp(node a,node b){
		return a.x>b.x;
	}
	void work(){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>aa[i].x>>aa[i].y>>aa[i].z;
		if(n<=30) dfs(1,0,0,0,0),cout<<ans<<'\n';
		else{
			bool f=false,f2=false;
			for(int i=1;i<=n;i++){
				if(aa[i].z!=0) f=true;
				if(aa[i].y!=0 && aa[i].z!=0) f2=true;
			}
			if(f2==false){
				sort(aa+1,aa+n+1,cmp);
				int sum=0;
				for(int i=1;i<=n/2;i++) sum+=aa[i].x;
				cout<<sum<<'\n';
			}else{
				sort(aa+1,aa+n+1,cmp);
				int sum=0;
				for(int i=1;i<=n;i++){
					if(i<=n/2)	
						sum+=aa[i].x;
					else if(i>n/2)
					   sum+=max(aa[i].x,aa[i].y);
				}
				cout<<sum;
			}
		}
	}
	signed main(){
		int T;
		cin>>T;
		while(T--) work();
		return 0;
	}
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return code::main();
}
/*
45
哎没办法
16：30 
70分 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
