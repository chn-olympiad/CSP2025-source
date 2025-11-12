#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,a[N],c[N];
int w[N];
long long ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		ans+=w[i];
	}
	int book=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	if(book==0){
		ans=0;
		sort(w+1,w+m+1,cmp);
		for(int i=k+1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans;
	}else if(k==0){
		cout<<ans;
	}else{
		cout<<ans;
	}
	return 0;
}
