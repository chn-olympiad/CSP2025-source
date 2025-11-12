#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int vis[100005];
int d1,d2,d3;
int n,ans,t;
int rec[100005],cnt;
void dfs(int x,int sum){
	if(x>n){
	//	cout<<sum<<endl;
		ans=max(ans,sum);
		
		return;
	}
	
//	for(int i=1;i<=3;i++){
		if(vis[x]==0) {
			
			if(d1<n/2){
				vis[x]=1;
				d1++;
				rec[x]=a[x].a;
				dfs(x+1,sum+a[x].a);
				d1--;
				vis[x]=0;
			}
			if(d2<n/2){
				vis[x]=1;
				d2++;
				rec[x]=a[x].b;
				dfs(x+1,sum+a[x].b);
				d2--;
				vis[x]=0;
			}
			if(d3<n/2) {
				vis[x]=1;
				d3++;
				rec[x]=a[x].c;
				dfs(x+1,sum+a[x].c);
				d3--;
				vis[x]=0;
			}
				
		}
//	}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
	
	} 
	ans=0;d1=0;d2=0;d3=0;
	dfs(1,0); 
	
	
	printf("%d\n",ans);
}
	return 0;
} 