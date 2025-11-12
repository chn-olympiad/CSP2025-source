#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,maxn,maxc,minn,minc;
int a1[100005],a2[100005],a3[100005],a[100005][3],f[100005],n,out,a1m,a2m,a3m;
struct p{
	int o;
	int c;
}b[100005];
int sc[5],m;
bool cmp(p x,p y){
	return x.c>y.c;
}
void dfs(int x,int ans){
	if(x>n){
		out=max(out,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sc[i]<n/2){
			sc[i]++;
			dfs(x+1,ans+a[x][i]);
			sc[i]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		out=0;
		a1m=0,a2m=0,a3m=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			a[i][1]=a1[i],a[i][2]=a2[i],a[i][3]=a3[i];
			a1m=max(a1m,a1[i]);
			a2m=max(a2m,a2[i]);
			a3m=max(a3m,a3[i]);
		}
		if(a2m==a3m && a2m==0){
			sort(a1+1,a1+n+1);
			for(int i=n;i>n/2;i--){
				out+=a1[i];
			}
			cout<<out<<'\n';
		}else if(a3m==0){
			for(int i=1;i<=n;i++){
				b[i].o=i;
				b[i].c=a1[i]-a2[i];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				out+=a1[b[i].o];
			}for(int i=n/2+1;i<=n;i++){
				out+=a2[b[i].o];
			}
			cout<<out<<'\n';
		}else{
			dfs(1,0);
			cout<<out<<'\n';
		}
	}
	return 0;
} 