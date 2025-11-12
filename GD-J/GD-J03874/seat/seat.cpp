#include <iostream>
#include <cmath>
using namespace std;int n,m,a1,a2,num=1,r=0;int main(){freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);cin>>n>>m>>a1;for(int i=1;i<n*m;i++){cin>>a2;if(a2>a1)num++;}int a3=num%(2*m),c=ceil(double(num)/double(m));if(a3>m){r=2*m-a3+1;}else if(a3==0) {r=1;}else r=a3;cout<<c<<' '<<r;return 0;} 
