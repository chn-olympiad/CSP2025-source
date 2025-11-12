#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
  	freopen("seat.out","w",stdout);
	int n,m,sc[1001],xr;
  	cin>>n>>m;
  	for(int i=1;i<=n*m;i++){
  		cin>>sc[i];
	}
	xr=sc[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(sc[i]<sc[j]){
				int cup;
				cup=sc[i];
				sc[i]=sc[j];
				sc[j]=cup;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(sc[i]==xr){
			xr=i;
		}
	}
	int lie,hang;
	if(xr%n!=0){
		lie=(xr/n)+1;
	}
	else{
		lie=xr/n;
	}
	if(lie%2==0){
		hang=n-(xr-n*(lie-1))+1;
	}
	else{
		hang=(xr-n*(lie-1));
	}
	cout<<lie<<" "<<hang;
	return 0;
}
