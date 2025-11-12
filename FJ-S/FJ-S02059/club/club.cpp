#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n;
long long ans,d[5];
long long vis[3*N];
struct store{
	int id,x,b;
}a[3*N];
bool cmp(store xx,store yy){
	return xx.b>yy.b;
}
void dfs(int ni,long long s){
	if(ni>=n*3||a[ni].b==0){
		ans=max(ans,s);
		return ;
	}
	for(int i=ni;i<=n*3;i++){
		if(vis[a[i].id]==0&&d[a[i].x]<n/2){
			d[a[i].x]++;
			vis[a[i].id]=1;
			dfs(i+1,s+a[i].b);
			d[a[i].x]--;
			vis[a[i].id]=0;
		}
	}
	ans=max(ans,s);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
		ans=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		d[1]=0,d[2]=0,d[3]=0;
		cin>>n;
		for(int i=1;i<=3*n;i++){
			cin>>a[i].b;
			if(i%3==0) a[i].x=3,a[i].id=i/3;
			else a[i].x=i%3,a[i].id=i/3+1;
		}
		sort(a+1,a+1+3*n,cmp);
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
