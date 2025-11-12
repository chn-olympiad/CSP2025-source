#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[4],mid,n,ans,b[11][10004],f[10001],k,m;
struct tt{
	int x,y,z;
}a[100005];
bool cmp(tt x,tt y){
	return x.z<y.z;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int l=n;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	} 
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		++n;
		for(int j=1;j<=b[i][0];j++){
			cin>>b[i][j];
			
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if(f[x]!=y){
			ans+=a[i].z;
			f[x]=y;
		}
	}
	cout<<ans;
}
