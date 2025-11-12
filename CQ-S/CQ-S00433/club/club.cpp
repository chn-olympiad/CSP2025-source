#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
int t,n,ans;
struct kkk{
	int x,y,z;
}a[N];
bool cmp(kkk x,kkk y){
	return x.x>y.x;
}
void dfs(int b,int c,int d,int e){
	if(b+c+d==n) ans=max(ans,e);
	else{
		if(b<n/2) dfs(b+1,c,d,e+a[b+c+d+1].x);
		if(c<n/2) dfs(b,c+1,d,e+a[b+c+d+1].y);
		if(d<n/2) dfs(b,c,d+1,e+a[b+c+d+1].z);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(n<100005){
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			dfs(0,0,0,0);
			cout<<ans<<"\n";		
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
		}
	}
}
/*
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
