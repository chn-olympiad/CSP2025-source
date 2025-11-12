#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) sum++;
	}
	cout<<sum/n+1<<' ';
	if((sum/n)%2==1) cout<<n-sum%n;
	else cout<<sum%n+1;
	return 0;
}
