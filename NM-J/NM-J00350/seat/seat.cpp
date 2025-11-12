#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s=0,c,r,n1[11],m1[11],t=0;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n;
	for(int i=n;i>=1;i--) n1[i]=i;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	for(int i=1;i<=n*m;i++){
    	for(int j=1;j<=n*m-1;j++){
    		if(a[j]<a[j+1]){
    			swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		//cout<<a[i];
		if(a[i]==s){
			s=i;
			continue;
		}
	}
	for(int i=1;i<=n;i++){
		if(s/n%2==0 && i*n%2!=0){
			if(s<n){
				r=s;
				//cout<<r;
				continue;
			} 
			else {
				r=s%n+1;
				continue;
			}
		}
		else {
			r=n1[i/n];
		}
	}
	for(int i=1;i<=m;i++){
		c=s/m+1;
	}
	cout<<r<<" "<<c;
    return 0;
}