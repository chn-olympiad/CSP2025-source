#include<bits/stdc++.h>
using namespace std;
int n,m,ansx,ansy,b;
int a[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)b=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	ansx=(n*m-b+1)/n;
	if((n*m-b+1)%n)ansx++;
	if(ansx%2){
		ansy=(n*m-b+1)-(ansx-1)*n;
	}
	else{
		ansy=n-((n*m-b+1)-(ansx-1)*n)+1;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
