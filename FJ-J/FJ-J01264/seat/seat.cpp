#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,l,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		l++;
		if(a[i]==k){
			break;
		}
	}
	if(l%n==0)  r=l/n;
	else	r=l/n+1;
	int sum=l-(r-1)*n;
	if(r%2==0){
		c=n-sum+1;
	}
	else c=sum;
	cout<<r<<" "<<c;
	return 0;
}