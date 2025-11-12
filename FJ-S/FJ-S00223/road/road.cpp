#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,f=0;
struct node{
	int u,v,w;
}a[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		f=0;
		if(cnt>=n){
			break;
		}
		for(int j=1;j<i;j++){
			if(a[i].u==a[j].u&&a[i].v==a[j].v){
				f=1;
				break;
			}
		}
		if(f==0){
			ans+=a[i].w;
			cnt++;
		}
	}
	cout<<endl<<ans;
	return 0;
}
