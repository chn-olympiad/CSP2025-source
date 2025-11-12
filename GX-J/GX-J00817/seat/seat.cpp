#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int hang;
int lie;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;

	cin>>n>>m;
	int xr,max,q=0,cum;
	cin>>xr;
	a[0]=xr;
	for(int i=1;i<=n*m;i++){
		cin>>q;
		a[i]=q;
		if(q>max){
			max=q;
		}
		q=0;
	}
	if(max==xr){
		cout<<"1 1";
		return 0;
	}	
	for(int i=1;i<=n*m;i++){
		if(a[i]<=a[i+1]){
			cum=a[i];
			a[i]=a[i+1];
			a[i+1]=cum;
		}
	}
	for(int i=0;i<=n*m;i++){
		if(a[i]==xr){
			hang=(i+1)/n+1;
			lie=(i+1)%n+1;
			}
		}

	cout<<hang<<" "<<lie;
		
		

	return 0;
}
