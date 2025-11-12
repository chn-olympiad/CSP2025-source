#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int c=1,r=0;
	for(int i=n*m;i>=1;i--){
		if(c%2==1){
			r++;
			if(r>n){
				r=n;
				c++;
			}
		}
		else{
			r--;
			if(r<1){
				r=1;
				c++;
			}
		}
		if(a[i]==x){
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
