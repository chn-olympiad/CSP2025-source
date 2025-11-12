#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,i,j;
	cin>>n>>m;
	int a[m*n];
	for(i=1;i<=m*n;i++){
		cin>>a[i];
	}
	if(a[0]=1)
		cout<<m<<" "<<n<<endl;
	else if(a[0]=m*n)
		cout<<1<<" "<<1<<endl;
	return 0;
}