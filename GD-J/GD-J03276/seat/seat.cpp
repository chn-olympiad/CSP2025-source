#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],s=0,k,q,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s++;
			cin>>a[s];
			if(i==1&&j==1){
				k=a[s];
			}
		}
	}
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--){
		if(a[i]==k){
			q=s-i+1;
		}
	}
	l=(q-1)/n+1;
	cout<<l<<" ";
	if(l%2==0){
		if((n+1)-q%n==n+1){
			cout<<1;
		}
		else{
			cout<<(n+1)-q%n;
		}
	}
	else{
		if(q%n==0){
			cout<<n;
		}
		else{
			cout<<q%n;
		}
	}
	return 0;
}
