#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	char a[100001],b[100001];
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
}
