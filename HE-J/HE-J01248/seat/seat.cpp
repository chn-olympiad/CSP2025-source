#include <iostream>
#include <cstdio>
using namespace std;
const int NM=105;
int n,m,a[NM],cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i+=1){
		cin>>a[i];
		if(a[i]>a[1])cnt+=1;
	}
	c=(cnt/n)+1;
	r=(c%2==1)?cnt%n+1:n-cnt%n;
	cout<<c<<" "<<r<<endl;
	return 0;
}
