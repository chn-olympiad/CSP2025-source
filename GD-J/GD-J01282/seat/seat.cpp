#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b[100];
	int n,m,xr,zw[2]={1,1};
	bool a=true;
	cin>>n>>m>>xr;
	b[0]=xr;
	for(int i=1;i<n*m;i++){
		cin>>b[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(b[j]<b[i]){
				swap(b[j],b[i]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==xr)
			break;
		zw[1]++;
		if(a)
			zw[0]++;
			if(zw[0]==n)a=false;
		else
			zw[0]--;
			if(zw[0]==0)a=true;
	}
	if(zw[1]%n==0){
		cout<<zw[1]/n<<' '<<n;
	}else{
		cout<<zw[1]/n+1<<' '<<zw[0];
	}
	return 0;
} 
