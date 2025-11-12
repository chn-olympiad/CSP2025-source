#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	int n;
	for(long long i=1;i<=c*r;i++){
		cin>>b[i];
		n=b[1];
	}
	
	sort(b+1,b+1+c*r);
	for(long long i=c*r;i>=1;i--){
		for(long long j=1;i<=c*r;){
			for(long long k=1;j<=r*c;k++){
				if(b[i]==n){
					cout<<j<<" "<<k;
					return 0;
				}
				if(k==c){
				j++;
				k--;
				if(k==0){
				j++;
				k=1;
				k++;
					}
				}
			}
		}
	}

	
	
	return 0;
}
