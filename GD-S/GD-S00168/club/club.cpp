#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010],b[100010],c[100010];
bool fa,fb,fc;
long long ans;
void dfs(int x,int aa,int bb,int cc,long long an){
	if(x>n){
		ans=max(ans,an);
		return;
	}
	if(aa+1<=n/2) dfs(x+1,aa+1,bb,cc,an+a[x]);
	if(bb+1<=n/2) dfs(x+1,aa,bb+1,cc,an+b[x]);
	if(cc+1<=n/2) dfs(x+1,aa,bb,cc+1,an+c[x]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		fa=fb=fc=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]) fa=0;
			if(b[i]) fb=0;
			if(c[i]) fc=0;
		}
		if(fa&&fb){
			sort(c+1,c+1+n);
			for(int i=n/2+1;i<=n;i++) ans+=c[i];
		}
		else if(fa&&fc){
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;i++) ans+=b[i];
		}
		else if(fb&&fc){
			sort(a+1,a+1+n);
			for(int i=n/2+1;i<=n;i++) ans+=a[i];
		}
		else if(n<=15) dfs(1,0,0,0,0);
		else for(int i=1;i<=n;i++) ans+=max(a[i],max(b[i],c[i]));
		cout<<ans<<"\n";
	}
	return 0;
}

