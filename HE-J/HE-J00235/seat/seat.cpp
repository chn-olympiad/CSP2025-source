#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int sum=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		sum=a[0];
	}
	int c,r;
	if(n==1&&m==1){
		c=1;
		r=1;
	}else{
		for(int i=0;i<n*m;i++){
			sort(a,a+n*m);
			for(int j=n;j>=0;j--){
				for(int t=m;t>=0;t--){
					if(a[i]==sum){
						c=j;
						r=t;
					}
				}
			}
		}
	}
	
	cout<<c<<" "<<r;
	return 0;
}
