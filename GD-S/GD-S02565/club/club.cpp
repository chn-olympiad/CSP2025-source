#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long T,n,ans;
bool vis[N];
struct node{
	long long x,y,z,id;
} a[N],b[N],c[N];
bool cmp_a(node A,node B){return A.x>B.x;}
bool cmp_b(node A,node B){return A.y>B.y;}
bool cmp_c(node A,node B){return A.z>B.z;}
void dfs(long long x,long long sum,long long A,long long B,long long C){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(A<n/2) dfs(x+1,sum+a[x].x,A+1,B,C);
	if(B<n/2) dfs(x+1,sum+a[x].y,A,B+1,C);
	if(C<n/2) dfs(x+1,sum+a[x].z,A,B,C+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool Z=false;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0) Z=true;
		}
		sort(a+1,a+1+n,cmp_a);
		if(Z==false){
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		long long ans_a=0,ans_b=0,ans_c=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
