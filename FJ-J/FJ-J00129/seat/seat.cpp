#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			t=a[i];
		}
	}
	sort(a,a+n*m);
	int s;
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			s=n*m-i;
			break;
		}
	}
	int ans1;
	if(s!=n){
		ans1=(s-s%n)/n+1;
	}else{
		ans1=(s-s%n)/n;
	}
	cout<<ans1<<" ";
	if(ans1%2==0){
		if(s==n){
			cout<<1<<endl;
		}else if(s%n==1){
			cout<<n<<endl;
		}else{
			cout<<n-s%n<<endl;	
		}
	}else{
		if(s==n){
			cout<<n<<endl;
		}else{
			cout<<s%n<<endl;
		}
	}
	return 0;
}
