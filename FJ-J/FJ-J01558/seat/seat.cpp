#include<bits/stdc++.h>
using namespace std;
int n,m,a[108],b,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m/2;i++){
		swap(a[i],a[n*m-1-i]);
	}
	for(int i=0;i<=n*m;i++){
		if(a[i]==b){
			x=i/n+1;
			if(x%2==0){
				y=n-(i%n);
			}
			else{
				y=i%n+1;
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
