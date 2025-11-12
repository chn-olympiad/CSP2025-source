#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1],loc=0;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		loc++;
		if(a[i]==s){	
			break;
		}
	}
	if(loc<=n){
		cout<<1<<' '<<loc<<endl;
		return 0;
	}
	int b;
	if(loc%n==0){
		b=loc/n;
	}else{
		b=floor(loc/n)+1;
	}
	cout<<b<<' ';
	if(b%2==0){
		int x=loc%n,r=n;
		while(--x!=0){
			r--;
		}
		cout<<r<<endl;
	}else{
		cout<<loc%n<<endl;
	}
	return 0;
}
