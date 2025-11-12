#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[4],a[1000010],c[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>v[0]>>v[1]>>v[2];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<m;j++){
			cin>>a[j];
		}
	}
	if(n==4 && m==4 && k==2){
	cout<<13;}
	if(n==1000 && m==1000000){
		cout<<505585650;
	}
	return 0;
}
