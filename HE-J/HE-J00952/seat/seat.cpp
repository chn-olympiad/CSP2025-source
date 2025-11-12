#include<bits/stdc++.h>
using namespace std;
int a[20000];
int main(){
    freopen("seat.in","r",stdin)
    freopen("seat.out","w",stdout)
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>a[i];
	}
	int sum=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) sum++;		
	}
	int t=sum/(2*n);
	int k=sum-t*n*2+1;
	if (k<=n) cout<<t*2+1<<" "<<k;
	else cout <<t*2+2<<" "<<2*n-k+1;
	return 0;
}
