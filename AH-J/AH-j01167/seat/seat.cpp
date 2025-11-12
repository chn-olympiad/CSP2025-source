#include<bits/stdc++.h>
using namespace std;
int m,n,cj,a,sum=1,s=1,i=1,j=1;
short z=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>a;
	for(int i=2;i<=m*n;i++)
		cin>>cj,sum+=(cj>a)?1:0;
	for(int k=1;k<=n*m;k++){
			i+=z;cout<<i<<' ';
			if(i>n) i--,j++,z*=-1;
			if(i<1) i++,j++,z*=-1;
			s++;
			if(s==sum) {cout<<j<<' '<<i;break;}}
	return 0;
}
