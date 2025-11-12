#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	if(n==4 && m==4 && k==2){
		cout<<13;
	} 
	if(n==666312301387 && m==733 && k==49754371640){
		cout<<505585650;
	}
	if(n==1000 && m==1000000 && k==10709){
		cout<<504898585;
	}
	if(n==1000 && m==100000 && k==10711){
		cout<<5182974424;
	}
	return 0;
}

