#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[15][15];
int n,m;
int zbl(){
	int d=m*n;
	while(d--){
		int maxi=0,o=0;
		for(int i=1;i<=m*n;i++){
			if(maxi<a[i]) maxi=a[i],o=i;
		}
		a[o]=0;
		return maxi;
	}
	return 0;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int c=a[1];
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=zbl();
				if(b[j][i]==c){
					cout<<i<<" "<<j<<endl;
					return 0;
				} 
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[j][i]=zbl();		
				if(b[j][i]==c){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
