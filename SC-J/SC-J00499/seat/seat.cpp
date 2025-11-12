#include<iostream>
#define ll long long
using namespace std;
int n,m,a1,ai;
int ni,mi,ra=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;++i){
		cin>>ai;
		if(ai>a1)ra++;
	}
	mi=ra/n;
	if(ra%n==0){
		if(ra/n%2==1)ni=n;
		else ni=1;
		cout<<mi<<" "<<ni;
	}
	else{
		ni=ra%n;
		if(ra/n%2==1)ni=n-ni+1;
		cout<<mi+1<<" "<<ni;
	}
	return 0;
}