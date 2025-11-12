#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>a[i];
	}
	int ans=0; 
	sort(a+1,a+m+1);
	for(int i=1;i<n;i++)
		ans+=a[i];
	cout<<ans-1;
	return 0;
}
