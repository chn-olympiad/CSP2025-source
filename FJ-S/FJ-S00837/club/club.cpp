#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct Node{
	long long a,b,c;
};
int t;
int n;
Node arr[N];
int f23;
int cmp(Node x,Node y){
	return x.a>y.a;
}
long long ans=0;
void dfs(long long x,long long a,long long b,long long c,long long zh){
	if(x>n){
		ans=max(ans,zh);
		return;
	}
	if(a+1<=n/2){
		dfs(x+1,a+1,b,c,zh+arr[x].a);
	}
	if(b+1<=n/2){
		dfs(x+1,a,b+1,c,zh+arr[x].b);
	}
	if(c+1<=n/2){
		dfs(x+1,a,b,c+1,zh+arr[x].c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		f23=1;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
			if(arr[i].b!=0||arr[i].c!=0){
				f23=0;
			}
		}
		if(f23){
			sort(arr+1,arr+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=arr[i].a;
			}
			printf("%lld\n",ans);
			continue;
		}else if(n==2){
			ans=max(ans,arr[1].a+arr[2].b); 
			ans=max(ans,arr[1].a+arr[2].c);
			ans=max(ans,arr[1].b+arr[2].a);  
			ans=max(ans,arr[1].b+arr[2].c); 
			ans=max(ans,arr[1].c+arr[2].a); 
			ans=max(ans,arr[1].c+arr[2].b);
			cout<<ans<<endl;
			continue;
		}
		dfs(2,1,0,0,arr[1].a);
		dfs(2,0,1,0,arr[1].b);
		dfs(2,0,0,1,arr[1].c);
		cout<<ans<<endl;
	}
	return 0;
}
