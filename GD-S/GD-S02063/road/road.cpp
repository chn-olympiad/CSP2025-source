#include <iostream>
using namespace std;
int a[1000005],b[1000005],c[1000005],d[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,p=0;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		p+=c[i];
	}
	cout<<p;
}
