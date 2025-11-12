#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)	sum++;
	}
	cout<<sum/n+1<<' ';
	if((sum/n+1)%2)	cout<<sum%n+1;
	else	cout<<n-sum%n; 
	return 0;
	
}
