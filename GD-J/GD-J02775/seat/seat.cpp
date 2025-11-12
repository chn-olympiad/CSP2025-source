#include<bits/stdc++.h>
using namespace std;

int n,m,a[1010],x,t;
int main() {
	freopen("sest.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--) {
		cout<<a[i]<<' ';
		if(a[i]==x) {
			t=n*m-i+1;
		}
	} 
	cout<<t<<endl;
	if(t%n==0) {
		if((t/n)%2==1) {
			cout<<t/n<<' '<<t%m+1;
		}
		else {
			cout<<t/n<<' '<<n-(t%m);
		} 		
	}
	else{
		if((t/n+1)%2==1) {
			cout<<t/n+1<<' '<<t%m;
		}
		else {
			cout<<t/n+1<<' '<<n-(t%m)+1;
		} 	
	}
//#Shang4Shan3Ruo6Shui4
	return 0;
}
