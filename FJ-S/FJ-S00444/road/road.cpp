#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a;
	for(int i=1;i<=m;i++){
		cin>>a;
		cin>>a;
		cin>>a;
	}
	for(int i=1;i<=k;i++){cin>>a;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a<<endl;
	}
	return 0;
}
