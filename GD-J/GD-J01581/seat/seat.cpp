#include<iostream>
using namespace std;
int n,m,a,t,sum=1,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>t;
		if(t>a) sum++;
	}
	if(sum%n==0) ans1=sum/n;
	else ans1=sum/n+1;
	if(ans1%2==1){
		if(sum%n==0) ans2=n;
		else ans2=sum%n;
	}
	else{
		if(sum%n==0) ans2=1;
		else ans2=n-sum%n+1;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
