#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m,n,s=1,h=1,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) s++;
	}
	while(s>n){
		h++;
		s-=n;
	}
	if(h%2!=0) cout<<h<<" "<<s;
	else cout<<h<<" "<<n-s+1;
	return 0;
}
