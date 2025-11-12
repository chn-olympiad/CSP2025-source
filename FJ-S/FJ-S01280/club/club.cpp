#include<bits/stdc++.h>//T1 10pts qwq
using namespace std;
const int N=1e5+5;
int n,m,T;
int ans=-1;
bool fg1,fg2;//特殊性质 
struct Node{
	int a,b,c;
}a[N];
bool cmp(Node x,Node y){
	return x.a>y.a;
} 


void dfs(int k,int x,int y,int z,int sum){
	//cout<<k<<" ";
	if(k==n){
		ans=max(ans,sum);
		return ;
	} 
	
	
	if(x<n/2) dfs(k+1,x+1,y,z,sum+a[k+1].a);
	if(y<n/2) dfs(k+1,x,y+1,z,sum+a[k+1].b);
	if(z<n/2) dfs(k+1,x,y,z+1,sum+a[k+1].c);
}

void dfs2(int k,int x,int y,int z,int sum){
	//cout<<k<<" ";
	if(k==n){
		ans=max(ans,sum);
		return ;
	} 
	
	
	if(x<n/2) dfs(k+1,x+1,y,z,sum+a[k+1].a);
	if(y<n/2) dfs(k+1,x,y+1,z,sum+a[k+1].b);
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0) fg1=1;
			if(a[i].c!=0) fg2=1;
		} 
		
		if(!fg1 && !fg2){
			//性质A
			int an=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=m;i++) an+=a[i].a;
			cout<<an;
			continue;
		}
		
		if(n==2){
			//就两个人直接对比 
			cout<<max({(a[1].a+a[2].b),(a[1].b+a[2].a),(a[1].a+a[2].c),(a[1].b+a[2].c),(a[1].c+a[2].b),(a[1].c+a[2].a)});
			continue;
		}
		
		if(fg2){
			dfs2(0,0,0,0,0);//特性B，然而还是TLE 
			cout<<ans<<'\n';
			continue;
		}
		
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	} 
	
		
	return 0;
}

/*




*/
