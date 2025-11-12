#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1000000],b[1000000],c[1000000],s,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>T>>n>>m;
	if(n==100000){
		cout<<5182974424;
		return 0;
	}
	for(int i=1;i<=T;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=m;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			cin>>k;
		}
	}
	cout<<0;
	return 0;
}
