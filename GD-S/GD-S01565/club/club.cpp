#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],b[N],c[N];
vector<int> v[3];
bool cmp(int x,int y){return c[x]-b[x]<c[y]-b[y];}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int ans=0;
		for(int i=0;i<=2;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=mx;c[i]=mx;
			if(mx==a[i][0]) v[0].push_back(i),b[i]=max(a[i][1],a[i][2]);
			else if(mx==a[i][1]) v[1].push_back(i),b[i]=max(a[i][0],a[i][2]);
			else v[2].push_back(i),b[i]=max(a[i][0],a[i][1]);
		}
		for(int i=0;i<=2;i++)
			if(v[i].size()>n/2){
				sort(v[i].begin(),v[i].end(),cmp);
				int lv=v[i].size();lv-=n/2;
				for(int k=0;k<lv;k++) ans+=b[v[i][k]]-c[v[i][k]];
			}
		printf("%d\n",ans);
	}
	return 0;
}
