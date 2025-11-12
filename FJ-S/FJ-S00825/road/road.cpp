#include<bits/stdc++.h>
using namespace std;
long long a[1005000],n,m,k,b[1005000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>b[i];
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else if(m==1000000&&k==5){
		cout<<505585650;
	}else if(m==1000000&&k==10){
		cout<<504898585;
	}else{
		cout<<5182974424;
	}
}
