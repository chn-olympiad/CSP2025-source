# include <bits/stdc++.h>
using namespace std;
int n,m;
long long int a[1001],w[90][90],sm,mc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	sm=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sm){
			mc=n*m-i+1;
			break;
		}
	}
	int c,r;
	c=mc/n+1;
	if(n==1){
		cout<<"1 "<<mc<<endl;
		return 0;
	}
	if(m==1){
		cout<<mc<<" 1"<<endl;
		return 0;
	}
	if(mc%n==0&&c%2==1){
		c=c-1;r=1;
		cout<<c<<" "<<r<<endl;
		return 0;
	}
	mc=mc-(c-1)*n;
	
	if(c%2==0){
		r=n-mc+1;
		if(r==0){
			c+=1;
			r=n;
		}
	}else{
		r=mc;
	}

	cout<<c<<" "<<r<<endl;
	 return 0;
}
