#include "bits/stdc++.h"
#define long long
using namespace std;
const int N=1e3+10;
int a[N];
int b,c;
signed main(){
   freopen("seat.in","r","stdin");
   freopen("seat.out","w","stdout");
     int n,m;
     cin>>n>>m;
     int sum=n*m;
     for(int i=1;i<=sum;i++){
		cin>>a[i]; 
		b=a[1];
	}
	sort(a+1,a+1+sum);
    for(int i=1;i<=sum;i++){
		if(a[i]==b){
			c=sum-i+1;
			}
	}
	int z;
	int x=c/n;
	int y=c%n;
	if(y!=0){
		  z=1;
		  }else{
			  z=0;
			  y=n;
			  }
	if((x+z)%2==1){
		cout<<x+z<<" "<<y;
		}
	if((x+z)%2==0){
		cout<<x+z<<" "<<n-y+1;
		}
   return 0;
}
