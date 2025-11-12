#include<bits/stdc++.h>
using namespace std;
long long int n,m,c,r,a[10000],t=1,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			t++;
		}
	}
	if(t%n == 0){
		z=n;
	}
	else{
		z=t%n;
	}
	cout<<(t-1)/n+1<<' '<<z;
	return 0;
}
