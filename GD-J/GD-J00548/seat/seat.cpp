#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],b[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=i;
	}
	for(int i=1;i<n*m;i++){
		for(int j=n*m;j>i;j--){
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
				swap(b[j],b[j-1]);
			}
		}
	}
	cout<<b[1]/n+1-(b[1]%n==0)<<' ';
	if((b[1]/n+(b[1]%n!=0))%2==1) cout<<b[1]%n+n*(b[1]%n==0);
	else cout<<n-b[1]%n-(b[1]%n==0)*n+1;
	
	return 0;
}
