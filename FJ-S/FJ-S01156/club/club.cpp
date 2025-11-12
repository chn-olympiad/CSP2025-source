#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}f[100005];
int t,n,nus[100005][5],ans,tmp;
bool cmp(node a,node b){
	if(a.a==b.a) return a.b<b.b;
	return a.a>b.a;
}
void dfs(int step,int numm,int f1,int f2,int f3){
	if(step>n){
		ans=max(ans,numm);
		return;
	}
	if(f1<n/2)dfs(step+1,numm+nus[step][1],f1+1,f2,f3);
	if(f2<n/2)dfs(step+1,numm+nus[step][2],f1,f2+1,f3);
	if(f3<n/2)dfs(step+1,numm+nus[step][3],f1,f2,f3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(nus,0,sizeof(nus));
		memset(f,0,sizeof(f));
		if(n<=30){
			for(int i=1;i<=n;i++){
				cin>>nus[i][1]>>nus[i][2]>>nus[i][3];
			}
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
 		}
		else{
			for(int i=1;i<=n;i++){
				cin>>f[i].a>>f[i].b>>tmp;
			}sort(f+1,f+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=f[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=f[i].b;
			cout<<ans<<endl;
		}
		
	}return 0;
}
