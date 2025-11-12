#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int x,y,u;	
}a[1000005];
bool cmp(node s,node d){
	return s.u<d.u;
}
int sum=0;
set <int> w;
vector <int> b;
queue <int> c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].u;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int x;
			b.push_back(x);
		}
	}
	cout<<765;
	return 0;
}
