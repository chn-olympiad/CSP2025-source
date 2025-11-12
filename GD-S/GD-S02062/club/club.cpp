#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
struct node{
	long long a,b,c;
}a[100010];
long long t,n,ans=0;
bool ca(node x,node y){
	return x.a>y.a;
}
void dfs(long long i,long long sum,node c){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	if((c.a+1)<=(n/2)){
		dfs(i+1,sum+a[i].a,{c.a+1,c.b,c.c});
	}
	if((c.b+1)<=(n/2)){
		dfs(i+1,sum+a[i].b,{c.a,c.b+1,c.c});
	}
	if((c.c+1)<=(n/2)){
		dfs(i+1,sum+a[i].c,{c.a,c.b,c.c+1});
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0){
				fa=0;
			}
			if(a[i].c!=0){
				fb=0;
			}
		}
		if(fa){
			int ans=0;
			sort(a+1,a+n+1,ca);
			for(int i=1;i<=(n/2);i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if(fb){
			int ans=0;
			node c;
			for(int i=1;i<=n;i++){
				if(a[i].a>a[i].b){
					if(c.a<(n/2)){
						ans+=a[i].a;
						c.a+=1;
					}else{
						ans+=a[i].b;
						c.b+=1;
					}
				}
				if(a[i].b>a[i].a){
					if(c.b<(n/2)){
						ans+=a[i].b;
						c.b+=1;
					}else{
						ans+=a[i].a;
						c.a+=1;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,{0,0,0});
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
