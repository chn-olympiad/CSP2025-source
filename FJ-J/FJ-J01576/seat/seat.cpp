#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],c,r,cnt=0;
int main(){
	//freopen("seat","r",stdin);
	//freopen("seat","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			cnt++;
		}
	}
	if((cnt/(n-(cnt%n)))%2!=0){
		if(cnt%n==0){
			r=cnt/(n-(cnt%n));
			c=cnt%n;
		}
		else if(cnt%n!=0){
			r=cnt/(n-(cnt%n))+1;
			c=cnt%n;
		}
	}
	else if((cnt/(n-(cnt%n)))%2==0){
		if(cnt%n==0){
			r=cnt/(n-(cnt%n));
			c=n-(cnt%n);
		}
		else if(cnt%n!=0){
			r=cnt/(n-(cnt%n))+1;
			c=n-(cnt%n);
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
