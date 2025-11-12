#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,r,c=0;
int main(){
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]>r){
			c++;
		}else{
			c++;
			break;
		}
	}
	if(c%n==0){
		if((c/n)%2==0){
			cout<<c/n<<" "<<1;
		}else{
			cout<<c/n<<" "<<n;
		}
	}else{
		if((c/n+1)%2==0){
			cout<<c/n+1<<" "<<n-(c%n)+1;
		}else{
			cout<<c/n+1<<" "<<c%n;
		}
	}
	return 0;
} 