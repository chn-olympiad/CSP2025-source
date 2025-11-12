#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		}
	for(int i=2;i<=m*n;i++){
		if(a[1]<a[i]) ans++;
		}
	int c,r;
	if(ans%n==0){
		if((ans/n)%2==0){
			r=1;
			c=ans/n;
			cout<<c<<' '<<r;
			return 0;
			} 
		else {
			r=n;
			c=ans/n;
			cout<<c<<' '<<r;
			return 0;
			}
		}
	else if(ans%n!=0){
		if((ans/n+1)%2==0){
			c=ans/n+1;
			r=n-(ans/n)+1;
			cout<<c<<' '<<r;
			return 0;
			}
		else{
			c=ans/n+1;
			r=ans%n;
			cout<<c<<' '<<r;
			return 0;
			}
		}
	return 0;
}
