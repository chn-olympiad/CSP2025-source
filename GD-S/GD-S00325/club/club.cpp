#include<bits/stdc++.h>
using namespace std;
struct tt{
	int x,id;
}b[100005],c[100005];
bool cmp(tt l,tt r){
	return l.x>r.x;
}
int n,a[100005][4],T,ans,h2,h3,vis[100005];
void dfs(int i,int xh1,int xh2,int xh3,int s){
	if(i==n+1) ans=max(ans,s);
	else{
		if(xh1+1<=n/2) dfs(i+1,xh1+1,xh2,xh3,s+a[i][1]);
		if(xh2+1<=n/2) dfs(i+1,xh1,xh2+1,xh3,s+a[i][2]);
		if(xh3+1<=n/2) dfs(i+1,xh1,xh2,xh3+1,s+a[i][3]);
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3],b[i].x=a[i][1];c[i].x=a[i][2],b[i].id=c[i].id=i;
			if(a[i][2]!=0) h2=1;
			if(a[i][3]!=0) h3=1;
		}
		if(h2==0&&h3==0){
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i].x;
			cout<<ans<<endl;continue;
		}else if(h3==0){
			int ans1=0;
			sort(b+1,b+1+n,cmp);sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i].x,ans1+=c[i].x;
			if(ans>ans1){
				for(int i=1;i<=n/2;i++) vis[b[i].id]=1;
				for(int i=1,j=1;i<=n/2;i++){
					while(vis[c[j].id]!=0) j++;
					ans+=c[j].x,j++;	
				}
			}else{
				for(int i=1;i<=n/2;i++) vis[c[i].id]=1;
				for(int i=1,j=1;i<=n/2;i++){
					while(vis[b[j].id]!=0) j++;
					ans1+=b[j].x,j++;	
				}
				ans=ans1;
			}
			cout<<ans<<endl;continue;
		}cout<<1<<endl;
		dfs(1,0,0,0,0);
		cout<<ans<<endl; 
	}
	return 0;
} 
