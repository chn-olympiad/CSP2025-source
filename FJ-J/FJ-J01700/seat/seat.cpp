#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[101],i,r,k;
	cin>>n>>m;
	for(i=0;i<n*m;i++) cin>>s[i];
	r=s[0];
	sort(s,s+n*m);
	for(i=n*m-1;i>=0;i--){
		if(s[i]==r){
			break;
		}
	}
	k=n*m-i-1;
	cout<<(k/n+1)<<" "<<((k/n+1)%2==0?n-k%n:k%n+1);
	return 0;
}
