#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],c=1,r=0,s=0,x=0;
bool f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			x=n*m-i+1;
		}
	}
	for(int i=1;i<=x;i++){
		
		if(r==n&&c%2==1){
			c++;
			f=1;
			r++;
		}
		else if(r==1&&c%2==0){
			c++;
			f=0;
			r--;
		}	
		if(f==0)r++;
		else r--;
		
	}
	cout<<c<<" "<<r;
	return 0;
}
