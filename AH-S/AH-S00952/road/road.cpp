#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,w,a,b,c,d,e;
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>a>>b>>c>>d>>e;
	}
	cout<<sum/2;
	return 0;
}
