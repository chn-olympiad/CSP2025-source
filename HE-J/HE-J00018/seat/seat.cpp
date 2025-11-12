#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000],b,k,c[1000];
int main(){
	freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	
	sort(a+1,a+1+n*m);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(c[1]==a[i])k=j;
	}
	cout<<k;
	if(k/n%2==1&&k!=n)cout<<k/n<<" "<<k%n;
	else if(k<=n)cout<<1<<" "<<k;
	else if(k/n%2==0)cout<<k/n<<" "<<n+1-k%n;
	return 0;
}
