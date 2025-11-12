#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int sum;
int a[117];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]<r){
			sum=i;
			break;
		}
	}
	cout<<sum<<' ';
	if((sum-1)/n%2==0)cout<<ceil(1.0*sum/n)<<' '<<(sum-1)%n+1;
	else cout<<sum/n+1<<' '<<n-sum%n+1;
	return 0;
}