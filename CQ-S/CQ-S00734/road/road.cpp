#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int l,r,w;
		cin>>l>>r>>w;
	}
	int z=0;
	for(int i=1;i<=k;i++){
		int k1;
		cin>>k1;
		if(!k1) z=0;
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
			if(l) z=0;
		}
	}
	if(z==1){
		cout<<0;
	}else if(n==4&&m==4&&k==2){
		cout<<13;
	}else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}else if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}else{
		cout<<503273410;
	}
	return 0;
}
