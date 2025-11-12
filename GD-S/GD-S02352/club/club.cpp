#include<bits/stdc++.h>
using namespace std;
const int N=100005;//需要降维 + 记忆化 
const int M=203;
int n;
int a[N][4];
int t;
int mx;
int f[M][M];
int dfs(int x,int y,int z,int ans){
	if(x+y+z==n){
		return ans;
	}
	int i=x+y+z+1;
	int a1,a2,a3;
	if(x+1<=mx)a1=dfs(x+1,y,z,ans+a[i][1]);
	if(y+1<=mx)a2=dfs(x,y+1,z,ans+a[i][2]);
	if(z+1<=mx)a3=dfs(x,y,z+1,ans+a[i][3]);
	return max(a1,max(a2,a3));
}
bool sa;
bool sb;
int b[N];
bool cmp(int x,int y){
	return x>y;
}
struct pr{
	int mx;
	int mxi;
	int mn;
	int mni;
};
pr pp[N];
bool cmp2(pr x,pr y){
	return x.mx<y.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sa=true;
		sb=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0) sa=false;
			if(a[i][3]!=0) sb=false;
		}
		mx=n/2;
		if(sa&&sb){
			int ans=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=mx;i++){
				ans+=b[i];
			}
			printf("%d\n",ans);
			continue;
		}
		
		else if(n>=200){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<"\n";
			continue;
		} 
		int ans=dfs(0,0,0,0);
		printf("%d\n",ans);
	}
	
	return 0;
} 
