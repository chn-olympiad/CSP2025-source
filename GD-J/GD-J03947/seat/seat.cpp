#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,l=1;
	int s[111];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	for(int i=2;i<=n*m;i++){
		if(s[i]>s[1]) l++;
	}
	x=ceil(float(l)/float(n));
	cout<<x<<' ';
	if(x%2==0){
		cout<<n*x-l+1;
	}
	else cout<<l-n*(x-1);
	return 0;
}
