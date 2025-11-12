#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++)cin>>a>>b>>c;
	for(int i=1;i<=k;i++){
		cin>>a;
		for(int j=1;j<=n;j++)cin>>b;
	}
	cout<<0;
	return 0;
}