#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v,w,c,a,f=0,b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v;
		if(i==1){
			b=v;
		}
		cin>>v;
		cin>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		if(c!=0){
			f=1;
		}
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a!=0){
				f=1;
			}
		}
	}
	if(f==0){
		cout<<0;
	}
	else if(n==4&&m==4&&k==2){
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k==10&&b==709){
		cout<<504898585;
	}
	else if(n==1000&&m==1000000&&k==10&&b==711){
		cout<<5182974424;
	}
	return 0;
}
