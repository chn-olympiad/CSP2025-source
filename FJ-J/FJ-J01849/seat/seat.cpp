#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],r=1,c=1,x=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(t==a[i]) x=n*m-i+1;
	}
	if(x==n*m){
		cout<<n<<" "<<m;
		return 0;
	}
	if(x<=n){
		for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			cout<<c<<" "<<r;
			return 0;
		}
		if(c%2==1){
			r++;
		}
		else{
			r--;
		}
		if(a[i-1]==t){
			cout<<c<<" "<<r;
			return 0;
		}
		if((c+1)%2==0&&r==n){
			r=n;
			c++;
		}
		else if((c+1)%2==1&&r==1){
			r=1;
			c++;
		}
		}
	}
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			cout<<c<<" "<<r;
			return 0;
		}
		if(a[i-1]==t){
			if(c%2==0){
				cout<<c<<" "<<r;
			}
			else {
				cout<<c<<" "<<r-1;
			}
			return 0;
		}
		if(c%2==1){
			r++;
		}
		else{
			r--;
		}
		if((c+1)%2==0&&r==n){
			r=n;
			c++;
		}
		else if((c+1)%2==1&&r==1){
			r=1;
			c++;
		}
	}
	return 0;
}
