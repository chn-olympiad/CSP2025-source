#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node{
	int x,y,z;
}a[N];
int n,m,ans;
bool cmp(node x,node y){
	return x.x>y.x;
}
void dfs(int xx,int yy,int zz,int x,int sum){
	if(x==n+1){
//		cout<<xx<<" "<<yy<<" "<<zz<<" "<<sum<<endl;
		ans=max(ans,sum);
		return;
	}else{
		if(xx<n/2) dfs(xx+1,yy,zz,x+1,sum+a[x].x);
		if(yy<n/2) dfs(xx,yy+1,zz,x+1,sum+a[x].y);
		if(zz<n/2) dfs(xx,yy,zz+1,x+1,sum+a[x].z);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if((a[i].y!=0)||(a[i].z!=0)) p=1;
		}
		if(p==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}else{
			dfs(0,0,0,1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
