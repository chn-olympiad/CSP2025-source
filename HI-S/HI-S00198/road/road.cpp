#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0; cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,l; cin>>x>>y>>l;
		a[x][y]=l;
		sum+=l;
	}for(int i=1;i<=k;i++){
		int x,s; cin>>x;
		for(int i=1;i<=n;i++){
			if(i==1) cin>>s;
			else{
				int y; cin>>y;
			}
		}
	}
	cout<<sum;
	return 0;
}
