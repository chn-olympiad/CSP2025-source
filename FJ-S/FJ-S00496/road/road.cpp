#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005],h=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>a[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	sort(a+1,a+1+m);
	int h=0;
	for(int i=1;i<n;i++){
		h+=a[i];
	}
	cout<<h;
	return 0;
} 
