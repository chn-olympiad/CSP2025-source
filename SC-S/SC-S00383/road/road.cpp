#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int num=0;
	for(int i=1;i<=m;i++){
		int a,b,f;
		cin>>a>>b>>f;
		num+=f;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
		}
	}
	cout<<num;
	return 0;
}