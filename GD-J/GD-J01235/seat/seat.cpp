#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],xr,rn,rm,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>xr;
	a[0]=xr;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==xr){
			s=n*m-i;
			break;
		}
	}
	if(s%n==0){
		rn=s/n;
		rm=m;
	}
	else{
		rn=s/n+1;
		rm=s%n;
	}
	if(rn%2==0){
		rm=m-rm+1;
	}
	cout<<rn<<' '<<rm;
	return 0;
}
