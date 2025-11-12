#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int xm;
int d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xm;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>xm) d++;
	}
	cout<<(d-1)/n+1<<' ';
	if(((d-1)/n+1)%2==1){
		if(d%n!=0)	cout<<(d)%n;
		else cout<<n;
	} 
	else{
		if(d%n!=0)	cout<<n-((d)%n)+1;
		else cout<<1;
	} 
	return 0;
}
