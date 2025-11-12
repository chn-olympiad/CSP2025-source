#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005],x,y;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		cin>>x>>y;
		cin>>a[x][y];
		ans+=a[x][y];}
	cout<<ans;
    return 0;}
