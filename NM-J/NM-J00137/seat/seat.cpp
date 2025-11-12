#include<bits/stdc++.h>
using namespace std;
int n,m,ai,num=1,a,c,r;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main(){
cin>>n>>m>>a;
for(int i=0;i<n*m-1;i++){
	cin>>ai;
	if(a<ai)num++;
}
c=(num-1)/n+1;
r=c%2?((num-1)%n)+1:(n-((num-1)%n));

cout<<c<<" "<<r;
return 0;
}

