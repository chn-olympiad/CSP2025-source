#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[0]<a[i]) k++;
	}
	cout<<k/n+1<<" ";
	if((k/n+1)%2==0) cout<<n-k%n;
	else cout<<k%n+1;
	return 0;
}
