#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],R,id,hang,lie;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==R){
			id=n*m-i;
		}
	}
	lie=(id-1)/n+1;
	if(lie%2==1){
		hang=(id-1)%n+1;
	}else{
		hang=(n+1)-(((id-1)%n)+1);
	}
	cout<<lie<<" "<<hang;
	return 0;
}
