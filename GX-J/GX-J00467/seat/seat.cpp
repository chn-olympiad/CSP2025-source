#include <iostream>
#include <math.h>
using namespace std;
long long i,j,n,m,cj,w;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>w;
	j=0;
	
	for(i=1;i<m*n;i++){
		cin>>cj;
		if(cj>w){
			j++;
		}
	}
	//cout<<j<<endl;
	if((j/n)%2==2||(j/n)%2==0){
		cout<<j/n+1<<' ';
		cout<<j%n+1;
		
		}
	if((j/n)%2==1){
	  cout<<j/n+1<<' ';
		cout<<n-(j%n);                                                                                                                                                                                                                                                                                                  (n%2);
		}
	return 0;
}
