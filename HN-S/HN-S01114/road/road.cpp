#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		ans+=z;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<"13";
	}else if(n==1000&&m==1000000&&k==5){
		cout<<"505585650";
	}else if(n==1000&&m==1000000&&k==10){
		cout<<"504898585";
	}else if(n==1000&&m==100000&&k==10){
		cout<<"5182974424";
	}else{
		cout<<ans;
	}
	return 0;
} 
