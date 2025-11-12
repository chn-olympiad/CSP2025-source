#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],sum=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		}
	}
	cout<<sum/n+1<<" ";
	if((sum/n+1)%2==0){
		sum=sum-(sum/n)*n;
		cout<<n-sum;
	}else{
		sum=sum-(sum/n)*n;
		cout<<sum+1;
	}
	return 0;
}

