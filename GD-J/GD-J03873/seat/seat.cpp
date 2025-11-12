#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,r,l,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int k;
		cin>>k;
		if(i==1)
			r=k;
		a[k]++;
	}
	for(int i=100;i>=1;i--){
		if(a[i] == 1)
			l++;
		if(i == r)
			break;
	}
	//cout<<l<<" ";
	m1 = l/n + (l%n != 0);
	//cout<<m1;
	if(m1 % 2 == 1)
		n1 = l%n;
	else
		n1 = n+1-(l%n);
	//cout<<n1;
	cout<<m1<<" "<<n1;
	return 0;
} 
