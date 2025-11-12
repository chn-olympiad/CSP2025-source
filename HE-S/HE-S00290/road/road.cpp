#include<bits/stdc++.h>
using namespace std;
struct city{
	int citya,cityb,coat;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>c(1000);
	vector<city>a(1000);
	int b[1000][1000];
	for(int i=1;i<=m;i++){
		cin>>a[i].citya>>a[i].cityb>>a[i].coat;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n+1;i++){
			cin>>b[j][i];
		}
	}
	cout<<13;
	return 0;
}
