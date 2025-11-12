#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			sum=n*m-i+1;
			break;
		}
	}
	int sum1=sum/n+1;
	int sum2=sum%n;
	if(sum2==0){
		sum1--;
		sum2=n;
	}
	if(sum1%2==1){
		cout<<sum1<<' '<<sum2;
	}
	else{
		cout<<sum1<<' '<<n-sum2+1;
	}
	return 0;
}
