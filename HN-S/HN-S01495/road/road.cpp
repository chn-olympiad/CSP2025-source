#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int w[1123456];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i],&w[i],&w[i]);
	}
	
	sort(w+1,w+m+1);
	
	int ans=0;
	
	for(int i=1;i<n;i++){
		ans+=w[i];
	}
	
	cout<<ans;
	
	return 0;
}
