#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n;
struct P{
	long long a,b,c;
} a[N];
long long n;
long long dfs(long long v,long long resa,long long resb,long long resc,long long ans){
	if(v>n){
		return ans;
	}
	long long res=0;
	if(resa<n/2){
		res=max(res,dfs(v+1,resa+1,resb,resc,ans+a[v].a));
	}
	if(resb<n/2){
		res=max(res,dfs(v+1,resa,resb+1,resc,ans+a[v].b));
	}
	if(resc<n/2){
		res=max(res,dfs(v+1,resa,resb,resc+1,ans+a[v].c));
	}
}
bool cmp1(P a,P b){
	if(a.a!=b.a){
		return a.a>b.a;
	}else{
		return a.b<b.b;
	}
}
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		bool p1=1,p2=1,p3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			vis[i]=0;
			if(a[i].b!=0||a[i].c!=0){
				p1=0;
			}
			if(a[i].c!=0){
				p2=0;
			}
		}
		if(p1){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<dfs(1,0,0,0,0)<<"\n";
	}
	return 0;
}

