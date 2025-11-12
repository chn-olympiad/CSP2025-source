#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,g[100005],ans,f[100005],tot,opt;
struct node{
	int a,b,c;
}a[100005];
int cmp(int x,int y){return x>y;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n; g[1]=g[2]=g[3]=0; opt=0; ans=0; tot=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b && a[i].a>=a[i].c) g[1]++,ans+=a[i].a;
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c) g[2]++,ans+=a[i].b;
			else if(a[i].c>=a[i].a && a[i].c>=a[i].b) g[3]++,ans+=a[i].c;
		}
		if(g[1]<=n/2 && g[2]<=n/2 && g[3]<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		if(g[1]>n/2) opt=1;
		else if(g[2]>n/2) opt=2;
		else opt=3;
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b && a[i].a>=a[i].c && opt==1){
				f[++tot]=max(a[i].b,a[i].c)-a[i].a;
			}
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c && opt==2){
				f[++tot]=max(a[i].a,a[i].c)-a[i].b;
			}
			else if(a[i].c>=a[i].a && a[i].c>=a[i].b && opt==3){
				f[++tot]=max(a[i].a,a[i].b)-a[i].c;
			}
		}
		sort(f+1,f+tot+1,cmp);
		for(int i=1;i+n/2<=tot;i++) ans+=f[i];
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

*/
