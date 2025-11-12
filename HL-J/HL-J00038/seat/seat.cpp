#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","r",stdout);
int m,n,r,k;
int s[100100];
	cin>>n>>m;
	k=m*n+1;
	for(int i=1;i<=k;i++){
		cin>>s[i];
	}
	r=s[1];
	 
	if(n==1){
		for(int i=m;i>=1;i--){
			if(r==s[i]){
				cout<<"1"<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
