#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
struct node{
	long long x,y,z;
}a[N];
long long ans=0;
bool fg1=true,fg2=true;
bool cmp1(node a,node b){
	return a.x>b.x;
}
void dfs(int s,long long num,int la,int lb,int lc){
	if(s==0){
		dfs(s+1,0,0,0,0);
		return;
	}
	if(s==n+1){
		ans=max(ans,num);
		return;
	}else{
		if(la<n/2) dfs(s+1,num+a[s].x,la+1,lb,lc);
		if(lb<n/2) dfs(s+1,num+a[s].y,la,lb+1,lc);
		if(lc<n/2) dfs(s+1,num+a[s].z,la,lb,lc+1);
	}
	return;
}
int main(){
	freopen("clud,in","r",stdin);
	freopen("clud.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		ans=0;
		fg1=true,fg2=true;
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			ans=max(max(max(a+e,a+f),max(b+d,b+f)),max(c+d,c+e));
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) fg1=false;
			if(a[i].z!=0) fg2=false;
		}
		if(fg1&&fg2){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
