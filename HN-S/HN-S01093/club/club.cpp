#include<bits/stdc++.h>
using namespace std; 
int t,n,a[100010],b[100010],c[100010],x,y,z,ans=0,mx[100010];
void dfs(int i,int sum,int x,int y,int z){
	if(i>=n){
		if(x<=n/2 && y<=n/2 && z<=n/2){
			ans=max(ans,sum);
		}
		return;
	}
	if(x>n/2 || y>n/2 ||z>n/2) return;
	i++;
	dfs(i,sum+a[i],x+1,y,z);
	dfs(i,sum+b[i],x,y+1,z);
	dfs(i,sum+c[i],x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		x=0,y=0,z=0;
		scanf("%d",&n);
		int r,r2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			mx[i]=max(max(mx[i],a[i]),max(b[i],c[i]));
			int l=0;
			if(a[i]==0) l++;
			if(b[i]==0) l++;
			if(c[i]==0) l++;
			if(l>=2) r++;
			if(l>=1) r2++;
		}
		if(r==n){
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}else if(r2==n){
			int op[100010];
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					op[i]=abs(b[i]-c[i]);
				}else if(b[i]==0){
					op[i]=abs(a[i]-c[i]);
				}else{
					op[i]=abs(a[i]-b[i]);
				}
			}
			sort(op+1,op+n+1);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					if(a[i]==0){
						ans+=max(b[i],c[i]);
					}else if(b[i]==0){
						ans+=max(a[i],c[i]);
					}else if(c[i]==0){
						ans+=max(a[i],b[i]);
					}
				}else{
					ans+=max(a[i],max(b[i],c[i]));
				}
			}
		}
		ans=0;
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
