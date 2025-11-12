#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,k=0,r;
	cin>>n>>m;
	int a[n*m];
	cin>>a1;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
	}
	for(int i=n*m-1;i>=0;i--)
		for(int j=0;j<=n*m-1;j++){
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	for(int i=0;i<n*m-1;i++){
		if(a[i]==a1) break;
		else k++;
	}
	r=k/n;
	cout<<r<<' ';
	if(r%2 == 0){
		r=k%n;
		r=n+(1-r);
		cout<<r;
	}
	else{
		r=n%k;
		cout<<r;
	}
	return 0;
}
