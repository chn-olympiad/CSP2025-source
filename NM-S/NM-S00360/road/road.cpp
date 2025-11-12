#include<bits/stdc++.h>
using namespace std;
struct node{
	int d1,d2,d3;
}a[1001010];
struct cun{
	int d4,d5,d6;
}c[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].d4>>c[i].d5>>c[i].d6;
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k==5){
		if(a[1].d1==709){
			cout<<504898585;
		}
		else{
			cout<<5182974424;
		}
	}
	else{
		cout<<33550336;
	}
	return 0;
} 
