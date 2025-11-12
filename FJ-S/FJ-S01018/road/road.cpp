#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[11],a[11],f[5000001],cnt,ans;
bool vis[5000001];
struct stu{
	int u,v,w,p;
}b[5000001];
bool cmp(stu x,stu y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
		b[i].p=0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int l=i+1;l<=n;l++){
				m++;
				b[m].u=j;
				b[m].v=l;
				b[m].w=a[j]+a[l]+c[i];
				b[m].p=i;
			}
		}
	}
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(b[i].u),y=find(b[i].v);
		if(x!=y){
			f[x]=f[y];
			cnt++;
			if(vis[b[i].p]==1&&b[i].p!=0){
				b[i].w-=c[b[i].p];
			}
			ans+=b[i].w;
			vis[b[i].p]=1;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
