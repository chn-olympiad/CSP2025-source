#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int n,m;
long long a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long zn=n*m;
	for(int i=1;i<=zn;i++){
		cin>>a[i];
	}
	long long x=a[1];
	sort(a+1,a+zn+1);
	for(int s=1;s<=zn;s++){
		long long i=zn-s+1;
		if(a[s]==x){
			int k=0;
			if(i%n==0)k=i/n;
			else k=i/n+1;
			int j=i%n;
			if(j==0){
				if(k%2==0){
					cout<<k<<" "<<1;
				}else{
					cout<<k<<" "<<n;
				}
				break;
			}else{
				if(k%2==0){
					cout<<k<<" "<<n-j+1;
				}else{
					cout<<k<<" "<<j;
				}
				break;
			}
		} 
	}
	return 0;
}