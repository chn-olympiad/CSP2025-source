#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100000],b[1100000],sum,now;
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
		b[i]=a[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		if(sum==b[i]){
			sum=i;
		}
	}
    if(sum%n==0)
	{
		cout<<sum/n<<" ";
		if((sum/n)%2==1){
			if(sum%n!=0)cout<<sum%n;
			else cout<<n;
		}
		else {
			if(sum%n==0)cout<<1;
			else {
				cout<<n-sum%n+1;
			}
		}
	}
	else {
		cout<<sum/n+1<<" ";
		if(((sum/n)+1)%2==1){
			if(sum%n!=0)cout<<sum%n;
			else cout<<n;
		}
		else {
			if(sum%n==0)cout<<1;
			else {
				cout<<n-sum%n+1;
			}
		}
	}
	return 0;
} 
