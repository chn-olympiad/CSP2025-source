#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,d,w;
}a[2000010];
long long tmx,n,m,k,t=0x3f3f3f3f3,v1[2000010];
bool cmp(node n1,node n2){
	return n1.w<n2.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].v>>a[i].d>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	int r=n;
	for(int i=1;i<n&&i<=r;i++){
		if(v1[a[i].v]==0||v1[a[i].d]==0){
			v1[a[i].v]=1;
			v1[a[i].d]=1;
			tmx+=a[i].w;
		}else{
			n++;
		}
	}
	n=r;
	for(int po=1;po<=k;po++){
		memset(v1,0,sizeof(v1));
		long long tx=0;
		int tt;
		cin>>tt;
		tx+=tt;
		for(int j=1;j<=n;j++){
			a[m+j].v=j;a[m+j].d=n+1;
			cin>>a[m+j].w;
		}
		sort(a+1,a+m+n+1,cmp);
		int l=n;
		for(int i=1;i<=n&&i<=l+m;i++){
			if(v1[a[i].v]==0||v1[a[i].d]==0){
				v1[a[i].v]=1;
				v1[a[i].d]=1;
				tx+=a[i].w;
			}else{
				n++;
			}
		}
		n=l;
		t=min(tmx,min(tx,t));
	}
	cout<<t;
	return 0;
}
