#include<bits/stdc++.h>
using namespace std;
int t,n,f[100005],a[100005],b[100005],c[100005];
long long ans;
void dfs(int x,int c1,int c2,int c3){
	if(x>n){
		long long res=0;
		for(int i=1;i<=n;i++){
			res+=f[i];
		}
		ans=max(res,ans);
	}
	for(int i=1;i<=3;i++){
		if(i==1 && c1<n/2){
			f[x]=a[x];
			dfs(x+1,c1+1,c2,c3);
		}
		if(i==2 && c2<n/2){
			f[x]=b[x];
			dfs(x+1,c1,c2+1,c3);
		}
		if(i==3 && c3<n/2){
			f[x]=c[x];
			dfs(x+1,c1,c2,c3+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(n>30){
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2;i--) ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

