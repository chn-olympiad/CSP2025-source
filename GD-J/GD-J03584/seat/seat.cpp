#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,r,c,a[110];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
		    k++;
		}
	}
	for(int i=n;i<=n*m;i+=n){
		if(k>=i-n&&k<i){
			int p=i/n;
			cout<<p<<" ";
			if(p%2){
				cout<<k-i+n+1;
			}
			else{
			    cout<<i-k;
			}
		}
	}
	return 0;
}
