#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],Max[100005],Maxid[100005],se[100005],seid[100005];
priority_queue<pair<int,int>> id[3];
int read(){
	char c=getchar();
	int x=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;i++) for (int j=1;j<=3;j++){
			a[i][j]=read(); 
			if (a[i][j]>Max[i]) se[i]=Max[i],seid[i]=Maxid[i],Max[i]=a[i][j],Maxid[i]=j;
			else if (a[i][j]>se[i]) se[i]=a[i][j],seid[i]=j;
		}
		for (int i=1;i<=n;i++){
			id[Maxid[i]].push({se[i]-Max[i],i});
			int j=Maxid[i];
			if (id[j].size()>n/2){
				int x=id[j].top().second; id[j].pop();
				id[seid[x]].push({-1e9,x});
			}
		}
		int ans=0;
		for (int i=1;i<=3;i++)
			while (!id[i].empty()){
				int x=id[i].top().second; id[i].pop();
				ans+=a[x][i];
			}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) Max[i]=Maxid[i]=se[i]=seid[i]=0;
	}
	return 0;
}
