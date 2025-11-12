#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct str{
	int a,b,c;
}a[N];
bool cmp1(str x,str y){
	return x.a>y.a;
}
int n;
ll ans;
void dfs(int i,int x1,int x2,int x3,ll s){
	if(i==n+1){
		ans=max(ans,s);
		return;
	}
	for(int j=1;j<=3;j++){
		if(j==1 && x1>0){
			dfs(i+1,x1-1,x2,x3,s+a[i].a);
		}else if(j==2 && x2>0){
			dfs(i+1,x1,x2-1,x3,s+a[i].b);
		}else if(j==3 && x3>0){
			dfs(i+1,x1,x2,x3-1,s+a[i].c);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool f=1,ff=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b>0 || a[i].c>0) f=0;
			if(a[i].c>0) ff=0;
		}
		if(f){
			sort(a+1,a+n+1,cmp1);
			ll sum=0;
			for(int i=1;i<=n/2;i++)
				sum+=a[i].a;
			cout<<sum<<'\n';
			continue;
		}
		ans=0;
		if(ff){
			dfs(1,n/2,n/2,0,0);	
		}
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
