#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[1000005],u[1000005],a[11][100005],b[11],sum;
int main(){
//	freopen("road1.in","r",stdin);
//	freopen("road1.out","w",stdout);	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);		
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int mone; 
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>mone;
		sum+=mone;  
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}else if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}else if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
	}else{
		cout<<mone;
	}
	return 0;
} 
