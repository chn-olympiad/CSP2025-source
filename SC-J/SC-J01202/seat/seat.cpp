#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int s[120];
int main(){
	int n,m,r,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	r=s[1];
	for(int i=2;i<=n*m;i++){
		if(s[i]>r){
			sum++;
		}
	}
	if(sum%n==0){
		if(sum/n%2==0){
			cout<<sum/n<<' '<<1;
		}else{
			cout<<sum/n<<' '<<n;
		}
	}else{
		if((sum/n+1)%2==0){
			cout<<sum/n+1<<' '<<n-sum%n+1;
		}else{
			cout<<sum/n+1<<' '<<sum%n;
		}
	}
	return 0;
}