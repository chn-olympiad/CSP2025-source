#include<bits/stdc++.h>
using namespace std;
int t,n,dp[5][100005],maxx,maxy,maxz,ans,ldnn,cwfn,pdd; 
struct asd{
	int x,y,z;
}a[100005];
bool cmp(asd X,asd Y){
	if(X.x==Y.x)
		return X.y>Y.y;
	else
		return X.x>Y.x;
}
void dfs(int xx,int yy,int zz,long long cnt,int cy){
	if(xx==n/2){
		if(yy==n/2){
			if(zz==n/2){
				if(cnt>ans){
					ans=cnt;
				}
				return;
			}
		}
	}
	if(cy==n+1){
		if(cnt>ans){
			ans=cnt;
		}
		return;
	}
	if(xx<n/2){
		dfs(xx+1,yy,zz,cnt+a[cy].x,cy+1);
	}
	if(yy<n/2){
		dfs(xx,yy+1,zz,cnt+a[cy].y,cy+1);
	}
	if(zz<n/2){
		dfs(xx,yy,zz+1,cnt+a[cy].z,cy+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		ldnn=0;
		cwfn=0;
		ans=0;
		maxx=0;
		maxy=0;
		maxz=0;
		pdd=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			maxx=max(maxx,a[i].x);
			maxz=max(maxz,a[i].z);
			maxy=max(maxy,a[i].y);
		}
		if(n==2){
			int t=a[1].x+a[2].y;
			int u=a[1].x+a[2].z;
			int r=a[1].y+a[2].x;
			int p=a[1].y+a[2].z;
			int e=a[1].z+a[2].y;
			int l=a[1].z+a[2].x;
			ans=max(t,u);
			ans=max(ans,r);
			ans=max(ans,p);
			ans=max(ans,e);
			ans=max(ans,l);
			cout<<ans<<endl;
			pdd=1;
		}
		if(maxz==0){
			if(maxy==0){
				for(int i=1;i<=n/2;i++){
					ans+=a[i].x;
				}
				cout<<ans<<endl;
				pdd=1;
			}
		}
		if(pdd==0){
			dfs(0,0,0,0,1);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
