#include<iostream>
#include<algorithm> 
using namespace std;
struct node{
	int x,y,z,maxn,id;
	void init(){
		if(x>y){
			if(x>z){
				maxn=x;
				id=1;
			}else{
				maxn=z;
				id=3;
			}
		}
		else{
			if(y>z){
				maxn=y;
				id=2;
			}else{
				maxn=z;
				id=3;
			}
		}
	}
}a[100005],b[100005];
int n,t,ans=0;
void dfs(int p,int sum,int x,int y,int z){
	if(p>n){
		ans=max(sum,ans);
		return;
	}
	if(x<n/2)
		dfs(p+1,sum+a[p].x,x+1,y,z);
	if(y<n/2)
		dfs(p+1,sum+a[p].y,x,y+1,z);
	if(z<n/2)
		dfs(p+1,sum+a[p].z,x,y,z+1);
}
bool cmp(node x,node y){
	if(x.x!=y.x)return x.x>y.x;
	return x.y>y.y;
}
bool cmp2(node x,node y){
	return x.y>y.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)f1=0;
			if(a[i].z!=0)f2=0;
			a[i].init();
		}
		if(f1){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}
		else if(f2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
				a[i].x=a[i].y=0;
			}
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].y;
				a[i].x=a[i].y=0;
			}
			int bns=0;
			sort(b+1,b+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				bns+=b[i].y;
				b[i].x=b[i].y=0;
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				bns+=b[i].x;
				b[i].x=b[i].y=0;
			}
			ans=max(ans,bns);
		}else{
			dfs(1,0,0,0,0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

25~40
*/ 
