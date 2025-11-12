#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,a[225];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			k=a[i];
			a[i]=a[i+1];
			a[i+1]=k;
		}
	}
	return 0;
}

