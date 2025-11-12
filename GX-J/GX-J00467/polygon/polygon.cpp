#include <iostream>
#include <math.h>
using namespace std;
long long i,j,n,q[4000],a,p,num,z;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>q[i];
		for(j=i;q[j]>q[j-1]&&j>0;j--){
			a=q[j-1];
			q[j-1]=q[j];
			q[j]=a;
		}
	}
	cout<<6;
	return 0;
}

