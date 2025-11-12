#include<iostream>
#include<fstream>
using namespace std;
int n,m,a,i,c,N;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(i=1;i<n*m;i++){
		cin>>c;if(c>a)N++;
	}cout<<N/n+1<<' '<<(N/n%2?n-N%n:N%n+1);

    return 0;
}

