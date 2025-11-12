#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,b;
	cin>>n>>m>>b;
	long long q=1;
	for(int i=1;i<n*m;i++){
		long long a;
		cin>>a;
		if(a>b) q++;
	}
	int h=q%n,l=q/n;
	if(h==0){
		if(l%2==1){
			cout<<l<<" "<<n;
		}else{
			cout<<l<<" "<<1;
		}
	}else{
		l++;
		if(l%2==1){
			cout<<l<<" "<<h;
		}else{
			cout<<l<<" "<<n-h+1;
		}
	}
	return 0;
}
