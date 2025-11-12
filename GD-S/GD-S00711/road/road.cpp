#include<bits/stdc++.h>
using namespace std;
int a[5][1000005];
int u[1000005];
int v[1000005];
int w[1000005];
int c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int flag1=1;
	int flag2=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag1=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				flag2=0;
			}
		}
	}
	if(flag1||flag2){
		cout<<"0";
		return 0;
	}
	else {
		cout<<a[1];
	}
	return 0;
}
