#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,da=0,zuo,lie,hang;
	bool yn=1;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int j=0;j<n*m;j++){
		if(a[0]>a[j]){
			da+=1;}
	}
	
	zuo=n*m-da;
	while(yn){
	if(zuo>m) {
		lie+=1;
		zuo-=m;}}
	if(zuo>0){
		if(lie%2==0){
			hang=m-zuo;
			cout<<lie<<" "<<hang<< endl;
		}
		else{
			hang=1+zuo;
			cout<<lie<<" "<<hang<< endl;
		}
	}

	}

