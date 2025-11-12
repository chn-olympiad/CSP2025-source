#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL t,n,ans,as,bs,cs,ti,ta;
struct node{
	LL x,y,z;
};
node a[100001];
bool cmp(node xm,node ym){
	return xm.x>ym.x;
}
void dfs(LL g,LL s){
	if(g==n){
		if(as<n/2){
			ans=max(ans,s+a[g].x);
			return;
		}
		if(bs<n/2){
			ans=max(ans,s+a[g].y);
			return;
		}
		if(cs<n/2){
			ans=max(ans,s+a[g].z);
			return;
		}
	}
	for(LL i=1;i<=3;i++){
		if(as<=n/2){
			as++;
			s=s+a[g].x;
			dfs(g+1,s);
			s=s-a[g].x;
			as--;
		}
		if(bs<=n/2){
			bs++;
			s=s+a[g].y;
			dfs(g+1,s);
			s=s-a[g].y;
			bs--;
		}
		if(cs<=n/2){
			cs++;
			s=s+a[g].z;
			dfs(g+1,s);
			s=s-a[g].z;
			cs--;
		}
		
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(LL k=0;k<t;k++){
		cin>>n;
		ans=0;
		memset(a,0,sizeof a);
		if(n<=30){
			for(LL i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
				if(a[i].y==0){
					ti++;
				}
				if(a[i].z==0){
					ta++;
				}
			}
			if(ti==n&&ta==n){
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].x;
				}
				cout<<ans;
				return 0;
			}
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
