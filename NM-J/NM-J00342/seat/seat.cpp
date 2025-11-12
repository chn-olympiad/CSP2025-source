#include <iostream>
#include <algorithm>
using namespace std;
bool fun(long long a,long long b){
    return a>b;
}
int main(){
	freopen("seat.in","i",stdin );
	freopen("seat.out","o",stdout );
	long long n=0,m=0;
	long long a[105]={},b[15][15]={};
	cin>>n>>m;
	long long c=n*m;
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	long long d=a[0],e=0;
	sort(a,a+c,fun);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			long long t=0;
			if(i%2==0){
				t=j+1;
			}else{
				t=n-j;
			}
			b[i][t-1]=a[e];
			if(a[e]==d){
				cout<<i+1<<" "<<t;
				break;
			}
			e++;
		}
		
	}
	
	
	
	return 0;
}
