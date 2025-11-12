#include<bits/stdc++.h>
using namespace std;
/*struct zzy{
	long long c,l[10001];
}b[1000001];*/
long long n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		/*a[q][w]=e;
		a[w][q]=e;*/
		ans+=e;
	}
	for(int i=1;i<=k;i++){
		int q;
		cin>>q;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
		}
	}
	cout<<ans;
	return 0;
}
