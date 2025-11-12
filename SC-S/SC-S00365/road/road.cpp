#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long s1=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		s1+=z;
	}
	long long s2=1e9+10;
	for(int i=1;i<=k;i++){
		long long t=0;
		int h;
		cin>>h;
		t+=h;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			t+=x;
		}
		s2=min(s2,t);
	}
	cout<<min(s2,s1);
	return 0;
}