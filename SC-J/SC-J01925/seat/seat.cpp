#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
long long m,n,a[101],seat[11][11],x,b[101],ansx,ansy,my,ga;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	my=a[1];
	sort(a+1,a+x+1);
	
	for(int i=1;i<=x;i++){
		b[i]=a[x-i+1];
	}
	for(int i=1;i<=x;i++){
		a[i]=b[i]; 
	}
	for(int i=1;i<=x;i++){
		if(a[i]==my){
			ga=i;
			break;
		}
	}
	ansx=(ga-1)/n+1;
	if(ansx%2){
		ansy=ga-ansx*n+n;
	}else{
		ansy=n-ga+ansx*n-n+1;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}