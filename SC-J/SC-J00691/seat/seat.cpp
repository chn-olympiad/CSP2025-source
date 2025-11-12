#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int l=a[1];
	sort(a,a+m*n+1,cmp);
	long long c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			if(i%2!=0) c=i/n+1;
			if(i%2==0) {
				c=i/n;
			}
			if(c%2==1 ){
				r=i%n;
			}
			if(c%2==0){
				r=n-i%n+1;
			}
			if(r==0) r=n;
		}
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}