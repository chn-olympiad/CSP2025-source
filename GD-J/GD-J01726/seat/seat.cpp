#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],rs;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	rs=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==rs){
			i=n*m-i;
			int c=ceil(i*1.0/n),r=c%2==0?(n-i+(c-1)*n+1):(i-(c-1)*n);
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
} 
