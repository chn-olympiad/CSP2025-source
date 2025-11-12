#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,c[1000010],s;
long long minn=1000000001;
struct node{
	int a,b;
}e[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].a>>e[i].b>>c[i];
	}
	sort(c+1,c+m+1);
	for(int i=1;i<=n-1;i++){
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}
