#include<bits/stdc++.h>
using namespace std;
int n,m,k,nxt[1000010],st[1000010],v[1000010],a[20][10010],c[20],h[1000010],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>st[i]>>nxt[i]>>v[i];
		h[st[i]]=i;
		h[nxt[i]]=i;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			v[i]=min(v[i],c[j]+a[j][st[i]]+a[j][nxt[i]]);
		}
	}
	for(int i=1;i<=m;i++){
		ans+=v[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
