#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int A(int x){
	int l=0,r=n*m,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x){
			return mid;
		}else if(a[mid]<x){
			r=mid;
		}else{
			l=mid;
		}
    }
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x;
	cin>>x;
	a[0]=x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+(n*m),greater<int>());
	x=A(x);
	cout<<x/n+1<<' ';
	if((x/n+1&1)==1){
		cout<<x%n+1;
	}else{
		cout<<n-x%n;
	}
	return 0;
}
