#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int num;
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			num=i;
		}
	}
	int c,r;
	c=ceil(num*1.0/n);
	if(num%n==0){
		r=n;
	}else{
		r=num%n;
	}
	if(c%2==0)		r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
