#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) continue;
		if(a[i]>a[1]) sum++;
	}
	cout<<sum/n+1<<" ";
	if((sum/n)%2==0) cout<<sum%n+1;
	else cout<<m-sum%n;
	return 0;
} 
