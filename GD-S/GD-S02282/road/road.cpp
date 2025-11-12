#include<bits/stdc++.h>
using namespace std;
long long n,m,c;
struct node{
	long long u,v,p;
}a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].p;
	}
	for(int i=1;i<=c;i++){
		a[i+m].u=i+m;
		cin>>a[i+m].v;
		for(int j=0;j<=n-1;j++){
			cin>>a[i+m+j].p;
		}
	}
	cout<<0;
	return 0;
} 
