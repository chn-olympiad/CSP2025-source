#include<bits./stdc++.h>
using namespace std;
long long a[100000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,p,r;
	cin>>n>>m>>r;
	for(int i=1;i<=m*n-1;i++) cin>>a[i];
	long long o=0;
	for(int i=1;i<m*n;i++){
		for(int i=2;i<m*n;i++){
			if(a[i]>a[i-1]){
				o=a[i-1];
				a[i-1]=a[i];
				a[i]=o;
			}
		}
	}
	long long x=2,lp=1;
	a[m*n]=-99999;
	for(int i=1;i<=m;i++){
		if(x%2==0){
			for(int j=1;j<=n;j++){ 
				if(r>a[lp]){
					cout<<i<<" "<<j;
					return 0;	
				}
				else lp++;
			}
		}
		if(x%2!=0) {
			for(int j=n;j>=1;j--){
				if(r>a[lp]){
					cout<<i<<" "<<j;
					return 0;
				}
				else lp++;
			}
		}
		x++;
	}
	return 0;
}
//thank CCF 
