#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k,r,c;

	cin>>n>>m;

	for(int i=1;i<=n*m-1;i++){
		cin>>s[i];
		k=s[1];
	}
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(s[i]==k){
			c=i/n+1;
			if(c%2==1){
				r=i/c;
				cout<<c<<" "<<r;
			} else if(c%2==0){
				r=n-i/n+1;
				cout<<c<<" "<<r;
			}
		}
	}
	
	return 0;
} 