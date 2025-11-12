#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a_1,index_a;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a_1=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a_1==a[i]){
			index_a=i+1;
		}
	}
	int d=index_a,cnt=0;
	while(d>n){
		d-=n;
		cnt++;
	}
	c+=cnt+1;
	if(c%2==1){
		r=n-index_a%n;
	}
	else r=n-index_a%n+1;
	cout<<c<<" "<<r<<endl;
}
