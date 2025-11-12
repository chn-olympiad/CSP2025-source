#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,a[100000100][100000010],mn=100000000000,b[10000000000],c[100000010][1000000010],d[10000000000],e=0;
	cin>>n>>m>>k;
	for(long long i=1;1<=m;i++){
		for(long long j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]<mn){
				
				mn=a[i][j];
				if(j=3){
					b[i]=mn;
					mn=100000000000;
					continue;
				}
			}
		}
		
	}
	for(long long i=1;1<=k;i++){
		for(long long j=1;j<=m+1;j++){
			cin>>c[i][j];
			if(c[i][j]<mn){
				
				mn=c[i][j];
				if(j=m+1){
					d[i]=mn;
					mn=100000000000;
					continue;
				}
			}
		}
	
		
	}
	for(long long i=1;i<=m;i++){
		e+=b[i];
	}
	for(long long i=1;i<=k;i++){
		e+=d[i];
	}
	cout<<e;
	return 0;
	
}
	
